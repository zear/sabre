/*
    Sabre Flight Simulator 
    Copyright (C) 1997	Dan Hammer

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 1, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/***************************************************************
 * Important to reverse the y directions to match the world    *
 * system where y increases in the 'up' direction              *
 ***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include "swap.h"

#define MAXLEN 70
#define NO_ERR 0
#define OUTFILE_ERR 1
#define INFILE_ERR 2
#define BUFFERGET_ERR 3

int color_counts[256];
int ncolors;
long textr_width;
long textr_height;
int nrows;
int ncols;
int ntextr = -1;
int textr_trans = -1;
char *pcx_file = NULL;
char *out_file = NULL;

char *id = NULL;
int renumber = -1;
int reverse_y = 0;

typedef struct rgb_struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} _rgb ;

typedef struct rgb_info_struct
{
  _rgb rgb;
  int  color;
  int  count;
  int  mapped_color;
} rgb_info;

rgb_info rgb_infos[256];

int found_palette;

typedef struct PCX_HEADER {
  int8_t  manufacturer;
  int8_t  version;
  int8_t  encoding;
  int8_t  bits_per_pixel;
  int16_t xmin, ymin;
  int16_t xmax, ymax;
  int16_t hres, vres;
  int8_t  palette16[48];
  int8_t  reserved;
  int8_t  color_planes;
  int16_t bytes_per_line;
  int16_t palette_type;
  int8_t  filler[58];
} pcx_header;

struct IMG {
  unsigned char  *buffer;
  unsigned int xsize;
  unsigned int ysize;
} image;

int count_colors(void);
void renumber_image(int);
void error_exit(int err, char *format, ...);

void write_tmap(FILE *f, char *id, long i, long j);
void write_tmap_rv(FILE *f, char *id, long i, long j);

char *format_byte(int );
void make_maps(char *);
void loadpcx(char *);
void write_palette(FILE *);
float calc_rgb_distance(_rgb *rgb);

void main(int argc, char *argv[])
{
  char *plt_file;
  FILE *pf;

  int tmp;
  fprintf(stderr,"mktextr3 07/19/97\n");
  if (argc < 6)
    {
      fprintf(stderr,"mktextr3 <pcx_file> <map_file> <id>"
	     " <image_width> <image_height>"
	     " [renumber] [reverse_y] [trans_color] \n");
      return;
    }
  pcx_file = argv[1];
  out_file = argv[2];
  id       = argv[3];
  textr_width = atoi(argv[4]);
  textr_height = atoi(argv[5]);
  if (argc >= 7)
    renumber = atoi(argv[6]);
  if (argc >= 8)
    reverse_y = atoi(argv[7]);
  if (argc == 9)
    textr_trans = atoi(argv[8]);

  fprintf(stderr," Input File: %s\n"
	 "Output File: %s\n"
	 "      width: %d\n"
	 "     height: %d\n",
	 pcx_file,out_file,textr_width,textr_height);
  if (renumber != -1)
    fprintf(stderr,"   renumber: %d\n",renumber);
  if (reverse_y != 0)
    fprintf(stderr,"  reverse_y: yes\n");
  if (ntextr != -1)
    fprintf(stderr,"     ntextr: %d\n",ntextr);
  loadpcx(pcx_file);

  nrows = image.ysize / textr_height;
  ncols = image.xsize / textr_width;

  tmp = nrows * ncols;
  if (ntextr == -1)
    ntextr = tmp;
  else if (ntextr > tmp)
    ntextr = tmp;
  fprintf(stderr,"Image xsize: %d\n"
         "Image ysize: %d\n"
         "  ntextures: %d\n",
	 image.xsize,
	 image.ysize,
	 ntextr);
  count_colors();
  if (renumber != -1)
    renumber_image(renumber);
  make_maps(out_file);
  if (*out_file == '-')
    plt_file = "mktextr3.plt";
  else
    {
      plt_file = (char *) malloc(strlen(out_file) + 10);
      sprintf(plt_file,"%s.plt",out_file);
    }
  pf = fopen(plt_file,"w");
  if (pf)
    write_palette(pf);
  else
    fprintf(stderr,"error opening %s for write\n",plt_file);
}

char *format_byte(int byte)
{
  static char return_buff[6];
  sprintf(return_buff,"%03u",byte);
  return (return_buff);
}

int count_colors()
{
  int i;
  ncolors = 0;
  for (i=0;i<256;i++)
    if (rgb_infos[i].count > 0)
      ncolors++;
}

float calc_rgb_distance(_rgb *rgb)
{
  float result;
  float dr,dg,db;

  dr = (float) rgb->r;
  dg = (float) rgb->g;
  db = (float) rgb->b;

  result = sqrt((dr * dr) + (dg * dg) + (db * db));
  return (result);
}

void renumber_image(int start)
{
  int points;
  int i,n;
  int flags[256];
  int flg;
  int  mincolor;
  int   mc;

  if (start < 0 || start > 255)
    error_exit(1,"%d: Invalid renumber",start);
  if (start + ncolors - 1 > 255)
    error_exit(1,"%d + %d colors exceeds 255",
	       start,ncolors);

  /*
  for (i=0;i<256;i++)
    {
      if (rgb_infos[i].count > 0)
	rgb_infos[i].mapped_color = start++;
    }

  return;
  */

  fprintf(stderr,"sorting ...\n");

  for (i=0;i<256;i++)
    {
      if (rgb_infos[i].count > 0)
	flags[i] = 1;
      else
	flags[i] = 0;
    }

  flg = 1;
  while (flg)
    {
      flg = 0;
      mincolor = sqrt((255 * 255) + (255 * 255) + (255 * 255)) + 100;
      for (i=0;i<256;i++)
	{
	  if (flags[i])
	    {
	      /*
	      mc = rgb_infos[i].rgb.r +
		rgb_infos[i].rgb.g +
		rgb_infos[i].rgb.b;
		*/
	      mc = calc_rgb_distance(&rgb_infos[i].rgb);
	      if (mc < mincolor)
		{
		  n = i;
		  flg = 1;
		  mincolor = mc;
		}
	    }
	}
      if (flg)
	{
	  if (mincolor == 0.0 && textr_trans != 0)
	    rgb_infos[n].mapped_color = 0;
	  else
	    rgb_infos[n].mapped_color = start++;
	  flags[n] = 0;
	}
      else
	break;
    }
}

void write_tmap(FILE *f, char *id_str, long i, long j)
{
  unsigned char  *bfptr,*bfptr2;
  int ii,jj;
  int cc;

  fprintf(f,"{\n");
  fprintf(f,"%s\n",id_str);
  fprintf(f,"%d %d %d\n",textr_width,textr_height,textr_trans);
  bfptr = image.buffer + (j * textr_width) + ((i+1) * ((long)image.xsize) * textr_height); 
  bfptr -= image.xsize;
  for (ii=0;ii<textr_height;ii++)
    {
      bfptr2 = bfptr;
      fprintf(f,"\t");
      for (jj=0;jj<textr_width;jj++)
	{
	  cc = (int) *bfptr2++;
	  
	  fprintf(f,"%s ", 
		  format_byte(rgb_infos[cc].mapped_color));
	}
      fprintf(f,"\n");
      bfptr -= image.xsize;
    }
  fprintf(f,"}\n");
}

void write_tmap_rv(FILE *f, char *id_str, long i, long j)
{
  unsigned char  *bfptr,*bfptr2;
  int ii,jj;
  int cc;

  fprintf(f,"{\n");
  fprintf(f,"%s\n",id_str);
  fprintf(f,"%d %d %d\n",textr_width,textr_height,textr_trans);
  bfptr = image.buffer + (j * textr_width) + (i * ((long)image.xsize) * textr_height); 
  for (ii=0;ii<textr_height;ii++)
    {
      bfptr2 = bfptr;
      fprintf(f,"\t");
      for (jj=0;jj<textr_width;jj++)
	{
	  cc = (int) *bfptr2++;
	  
	  fprintf(f,"%s ", 
		  format_byte(rgb_infos[cc].mapped_color));
	}
      fprintf(f,"\n");
      bfptr += image.xsize;
    }
  fprintf(f,"}\n");
}

void make_maps(char *path)
{
  FILE *f;
  long i,j;
  char id_str[9];
  int n = 0;
  
  if (*path == '-')
    f = stdout;
  else
    {
      if ((f = fopen(path,"w")) == NULL)
	error_exit(1,"Couldn't open %s",path);
    }

  /* Make texture maps */
  fprintf(f,"%d\n",ntextr);
  
  /* 
     The reverse_y flag really means preserve the
     original direction of the bitmap, where y  
     increases as you move down. The normal 
     conversion reverses this to match the
     standard coordinant system
     */
  if (reverse_y)
    {
      for (i=0;i<nrows,n < ntextr;i++)
	{
	  for (j=0;j<ncols;j++)
	    {
	      sprintf(id_str,"%s%02d%02d",
		      id,i,j);
	      fprintf(stderr,"texture: %s\n",id_str);
	      write_tmap_rv(f,id_str,i,j);
	      n++;
	      if (n >= ntextr)
		break;
	    }
	}
    }
  else
    {
      for (i=nrows-1;i>=0,n < ntextr;i--)
	{
	  for (j=0;j<ncols;j++)
	    {
	      sprintf(id_str,"%s%02d%02d",
		      id,i,j);
	      fprintf(stderr,"texture: %s\n",id_str);
	      write_tmap(f,id_str,i,j);
	      n++;
	      if (n >= ntextr)
		break;
	    }
	}
    }
}

void write_palette(FILE *f)
{
  int i;
  for (i=0;i<256;i++)
    if (rgb_infos[i].count > 0)
      fprintf(f,"\t(%d %d %d %d)\n",
	      rgb_infos[i].mapped_color,
	      rgb_infos[i].rgb.r / 4, 
	      rgb_infos[i].rgb.g / 4, 
	      rgb_infos[i].rgb.b / 4 );
}

void loadpcx(char * filename)
{
  FILE *infile;
  char  * ImagePtr;
  unsigned int x, i=0;
  unsigned int Points;
  int c;
  pcx_header pcxhead;

  fprintf(stderr,"loading pcx ...\n");
  for (i=0;i<256;i++)
    rgb_infos[i].count = 0;

  found_palette = 0;
  if ((infile=fopen(filename,"rb"))==NULL)
    error_exit(1,"Couldn't Open %s",filename);
  fseek(infile,0L,SEEK_SET);
  fread(&pcxhead,sizeof(pcx_header),1,infile);
  pcxhead.xmin = ltohs(pcxhead.xmin);
  pcxhead.xmax = ltohs(pcxhead.xmax);
  pcxhead.ymin = ltohs(pcxhead.ymin);
  pcxhead.ymax = ltohs(pcxhead.ymax);
  pcxhead.hres = ltohs(pcxhead.hres);
  pcxhead.vres = ltohs(pcxhead.vres);
  image.xsize = (pcxhead.xmax-pcxhead.xmin) + 1;
  image.ysize = (pcxhead.ymax-pcxhead.ymin) + 1;
  fprintf(stderr,"xsize: %d, ysize %d\n",
	  image.xsize,
	  image.ysize);
  Points = image.xsize * image.ysize;
  image.buffer = (char  *) malloc(Points);
  if(image.buffer==NULL)
    error_exit(1,"Failed to allocate %d bytes",Points);
  ImagePtr=image.buffer;
  for (i=0;i<Points;++i)
    {
      c=fgetc(infile) & 0xff;
      if((c & 0xc0) == 0xc0)
	{
	  x=c & 0x3f;
	  c=fgetc(infile);
	  while(x--)
	    {
	      *(ImagePtr++)=c;
	      rgb_infos[c].count++;
	      i++;
	    }
	  i--;
	}
      else
	{
	  *(ImagePtr++)=c;
	}
    }
  c = fgetc(infile);
  if (((int)c) == 12)
    {
      fprintf(stderr,"Found extended palette\n");
      found_palette = 1;
      for (i=0;i<256;i++)
	{
	  fread(&rgb_infos[i].rgb,3,1,infile);
	  rgb_infos[i].color = i;
	  rgb_infos[i].mapped_color = i;
	}
    }
  fclose(infile);
}

void error_exit(int err, char *format, ...)
{
  va_list ap;
  va_start(ap,format);
  vfprintf(stderr,format,ap);
  va_end(ap);
  fprintf(stderr,"\n");
  if (err > 0)
    {
      fprintf(stderr,"Exiting ...\n");
      exit(err);
    }
}


