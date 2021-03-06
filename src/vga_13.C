/*
    Sabre Fighter Plane Simulator 
    Copyright (c) 1997/98 Dan Hammer
    Portions Donated By Antti Barck

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
/*************************************************
 *           Sabre Fighter Plane Simulator       *
 * File   : vga_13.C                             *
 * Author : Dan Hammer                           *
 * low-level graphics routines using svgalib     *
 *                                               *
 * 12/97 Antti Barck: gdev library               *
 * 04/98 sync with windows vga_13.h              *
 * 12/98 David Vandewalle : SDL port             * 
 *************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "grafix.h"
#include "traveler.h"
#include "vga_13.h"
#include "ddaline.h"
#ifdef HAVE_LIBSDL
#include <SDL/SDL.h>
int FilterEvents(const SDL_Event *event);
SDL_Surface *screen; 
#else
#include "gdev-svgalib.h"
#endif

/*
  Define our own "vgamodes"
 */
#define G320x200x256  0
#define G640x480x256  1
#define G800x600x256  2
#define G1024x768x256 3

/* 
   These are now private to vga_13 module.
   Use lock_xbuff() to get pointer to 
   current screen buffer.
   */
static unsigned char *xbuffer;
static unsigned char *buffer_ptr;
static unsigned char *screen_ptr;

float         aspect_ratio    = 1.0;
int           SCREEN_WIDTH    = 320; 
int           SCREEN_PITCH    = 320;
int           SCREEN_HEIGHT   = 200;
int           MXSCREEN_WIDTH  = 320;
int           MXSCREEN_HEIGHT = 200;
int           MAX_X           = 319;
int           MAX_Y           = 199;
int           VGAMODE         = G320x200x256;
int           PALETTE_SIZE    = 768;
int           N_COLORS        = 256;

int           window_width      = 0;
int           window_height      = 0;

int           wx0,wy0,wx1,wy1;
SimFont       *g_font = NULL;
Rect          cliprect(0,0,319,199);

#define GDEV_SCREEN_DIM 1
#define GDEV_WINDOW_DIM 0

void init_vga_13(void)
{
  int dimx,dimy;

  /* switch on vgamode to get x,y dims */
  switch (VGAMODE)
    {
    case G320x200x256:
      dimx = 320;
      dimy = 200;
      break;

    case G640x480x256:
      dimx = 640;
      dimy = 480;
      break;

    case G800x600x256:
      dimx = 800;
      dimy = 600;
      break;

    case G1024x768x256:
      dimx = 1024;
      dimy = 768;
      break;

    default:
      printf("svgalib mode %d not allowable, defaulting to G320x200x256\n",
	     VGAMODE);
      VGAMODE = G320x200x256;
      dimx = 320;
      dimy = 200;
      break;
    }

#ifdef HAVE_LIBSDL
  // maybe now would be a good time to do some SDL init?
  // sure, why not!
  // This is where to add SDL sound init later if needed ...
  
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
     {
     fprintf(stderr,"Error during SDL init. SDL_Get_Error(): %s\n"
                    "Exiting to OS ...\n",
             SDL_GetError());     
     exit(0);        
     } 
  SDL_WM_SetCaption("Sabre - SDL Version", "Sabre"); 
  SDL_SetEventFilter(FilterEvents);
  SDL_EventState(SDL_MOUSEMOTION, SDL_ENABLE);
#else    
  /* Create gdev for svgalib */
  assign_gdev_svgalib();
  /* Create rgbdev for svgalib */
  assign_rgbdev8_svgalib();
#endif

//
//  Setup the viewing window size ...
//
#ifdef HAVE_LIBSDL // viewing windows are kinda stupid under SDL. I cut em out.
                   // maybe hack through the rest of the code later, and hack
                   // em all out for speed.
window_width  = dimx;
window_height = dimy;
                      
#else
  if (window_width == 0)
    window_width = dimx;
  if (window_height == 0)
    window_height = dimy;
#endif

//
// Next setup the video mode ...
//


#ifdef HAVE_LIBSDL
// this is where we try to get our video mode

   window_width = dimx;
   window_height = dimy;

// register the SDL cleanup function ...
   atexit(SDL_Quit);

// then  setup the display ...

//   SDL_Surface *screen; is define above ...
   screen = SDL_SetVideoMode(dimx, dimy, 8, 
                             SDL_HWSURFACE|SDL_HWPALETTE); //|SDL_FULLSCREEN
   if (screen == NULL) 
      { 
      fprintf(stderr, "Couldn't set SDL video mode: %s\n",
              SDL_GetError());
      exit(1);   
      }
      
// now setup all of the Sabre stuff to point to our new buffer ...
   xbuffer    = (unsigned char *) screen->pixels;
   screen_ptr = xbuffer;
   buffer_ptr = xbuffer;
	 
   SCREEN_WIDTH = dimx;    
   SCREEN_HEIGHT = dimy;   
   MXSCREEN_WIDTH = dimx;  
   MXSCREEN_HEIGHT = dimy; 
   MAX_X = SCREEN_WIDTH - 1;
   MAX_Y = SCREEN_HEIGHT - 1;
   cliprect.topLeft.x = 0;
   cliprect.topLeft.y = 0;
   cliprect.botRight.x = MAX_X;
   cliprect.botRight.y = MAX_Y;
   aspect_ratio = calc_aspect_ratio(MXSCREEN_WIDTH,MXSCREEN_HEIGHT);
   SCREEN_PITCH = SCREEN_WIDTH;
#else
  /* 
     Try twice, once with desired dims, 
     next with standard VGA 320x200 if desired dims
     are not available
  */
  int goodOpen = 0;
  for (int i=0;i<2;i++)
    {
      if (G->open(dimx,dimy,8,window_width,window_height) == 0)
	{
	  G->clear(0,3);
	  /* always point to buffered screen */
	  xbuffer    = (unsigned char *) G->getvbuf();
	  screen_ptr = xbuffer;
	  buffer_ptr = xbuffer;
	  SCREEN_WIDTH = G->getdimx(GDEV_WINDOW_DIM);
	  SCREEN_HEIGHT = G->getdimy(GDEV_WINDOW_DIM);
	  MXSCREEN_WIDTH = G->getdimx(GDEV_SCREEN_DIM);
	  MXSCREEN_HEIGHT = G->getdimy(GDEV_SCREEN_DIM);
	  MAX_X = SCREEN_WIDTH - 1;
	  MAX_Y = SCREEN_HEIGHT - 1;
	  cliprect.topLeft.x = 0;
	  cliprect.topLeft.y = 0;
	  cliprect.botRight.x = MAX_X;
	  cliprect.botRight.y = MAX_Y;
	  aspect_ratio = calc_aspect_ratio(MXSCREEN_WIDTH,MXSCREEN_HEIGHT);
	  goodOpen = 1;
	  SCREEN_PITCH = SCREEN_WIDTH;
	}
      if (!goodOpen && i==0)
	{
	  printf("%dx%d mode not available, using 320x200\n",dimx,dimy);
	  dimx = 320;
	  dimy = 200;
	  if (window_width > dimx)
	    window_width = dimx;
	  if (window_height > dimy)
	    window_height = dimy;
	}
      else
	break;
    }

  if (!goodOpen)
    {
      /* couldn't even open a 320x200 VGA mode ... */
      printf("Unable to set video mode ... exiting\n");
      exit(1);
    }
#endif

}

void restorecrtmode()
{
#ifdef HAVE_LIBSDL
   //  we are in X11, never touched the CRT mode to begin with. 
   //  soooooo do nothing as the atexit() stuff will do our cleanup.
#else
  G->close();
#endif
}

float calc_aspect_ratio(float width, float height)
{
  float ideal_vert;
  ideal_vert = width * 2.8 / 4.0;
  return (height / ideal_vert);
}

void blit_buff()
{
#ifdef HAVE_LIBSDL
   SDL_UpdateRect(screen, 0, 0, 0, 0);
#else
   G->update();
#endif
}

void clear_scr(int color)
{
  clear_scr(color,MAX_Y);
}

void clear_scr(int color, int row)
{
#ifdef HAVE_LIBSDL
SDL_Rect ScreenClearRect;         // no optimize, not a freq call. (I think)

ScreenClearRect.x = 0;
ScreenClearRect.y = 0;
ScreenClearRect.w = MAX_X;
ScreenClearRect.h = row+1;        // overrun bug here??  check it out for sure.
// possible BUG !!

SDL_FillRect(screen, &ScreenClearRect, (Uint32) color);   
#else
  G->rect(0,0,SCREEN_WIDTH,row+1,(int) color);
#endif
}

void fill_rect(Rect &r, int color)
{
#ifdef HAVE_LIBSDL
  SDL_Rect FillRect;   
  
  if (valid_rect(r))       
    {
      Rect r0 = r;
      cliprect2rect(cliprect,r0);
      FillRect.x = r0.left();
      FillRect.y = r0.top();
      FillRect.w = RWIDTH(r0);
      FillRect.h = RHEIGHT(r0);
      SDL_FillRect(screen, &FillRect, (Uint32) color);   
    }   
#else
  if (valid_rect(r))
    {
      Rect r0 = r;
      cliprect2rect(cliprect,r0);
      G->rect(r0.left(),r0.top(),RWIDTH(r0),RHEIGHT(r0),color);
    }
#endif
}

void putpixel(int x, int y, int color)
{
  if (x < SCREEN_WIDTH && x >= 0 && y < SCREEN_HEIGHT && y >= 0)
    *(buffer_ptr + (y * SCREEN_PITCH) + x) = (char ) color;
}

void h_line(int x, int y, int len, int color)
{
  register unsigned char *bf = buffer_ptr + (y * SCREEN_PITCH) + x;
  while (len--)
    *bf++ = color;
}

void v_line(int x, int y, register int len, int color)
{
  register unsigned char *bf = buffer_ptr + (y * SCREEN_PITCH) + x;
  while(len--)
    {
      *bf = color;
      bf += SCREEN_PITCH;
    }
}

void set_rgb_value(int color, char red, char green, char blue)
{
#ifdef HAVE_LIBSDL
// this is a palette set function
// Gonna have to set cursor remap in here someday!

//
// DANGER!!!!  The SDL version of this routine has been modified to do gamma
//             correction on the palette when it is set with this function.
//             
//             This banks on the current behavior of Sabre ... basically Sabre
//             only calls this function when first loading the palette, so 
//             everything works OK.
//            
//             This is also DIRT slow, cause it uses the evil floating point
//             number.



// typedef struct {
//        Uint8 r;
//        Uint8 g;
//        Uint8 b;
//        Uint8 unused;
// } SDL_Color;

SDL_Color ColorStruct;
/*
ColorStruct.r = (unsigned char)
       (pow(
           ((float)red/(float)255),
           (float)1/GAMMA_CORRECTION
           ) * 255);


ColorStruct.g = (unsigned char)
       (pow(
           ((float)green/(float)255),
           (float)1/GAMMA_CORRECTION
           ) * 255);


ColorStruct.b = (unsigned char)
       (pow(
           ((float)blue/(float)255),
           (float)1/GAMMA_CORRECTION
           ) * 255);
*/
ColorStruct.r = (unsigned char)red << 2;
ColorStruct.g = (unsigned char)green << 2;
ColorStruct.b = (unsigned char)blue << 2;

SDL_SetColors(screen,&ColorStruct,color,1);
#else
  RGB8->set(color,red,green,blue);
#endif
}

void get_rgb_value(int color, char *red, char *green, char *blue)
{
#ifdef HAVE_LIBSDL
// this gets a RGB tuple from the current palette
*red   = screen->format->palette->colors[color].r;
*green = screen->format->palette->colors[color].g;
*blue  = screen->format->palette->colors[color].b;

#else
  RGB8->get(color,red,green,blue);
#endif
}

void set_palette(int startcolor, int endcolor, char *palette)
{
// this is a palette set function that reads tupples of 3 bytes in RGB order
// and sets them into the palette at the appropriate slot.

#ifdef HAVE_LIBSDL
// Gonna have to set cursor remap in here!


SDL_Color *ColorStructPtr = new SDL_Color[endcolor - startcolor];

for(int x=startcolor;x<=endcolor;x++)
   {
   ColorStructPtr[x].r = *(palette++);
   ColorStructPtr[x].g = *(palette++);
   ColorStructPtr[x].b = *(palette++);
   }

SDL_SetColors(screen,ColorStructPtr, startcolor,endcolor - startcolor);

delete ColorStructPtr;


#else
  RGB8->set(palette,startcolor,endcolor);
#endif
}

void get_palette(int startcolor, int endcolor, char *palette)
{
#ifdef HAVE_LIBSDL
// this gets a block of palette entries in one call.

for(int x=startcolor;x<=endcolor;x++)
   {
   *(palette++) = screen->format->palette->colors[x].r;
   *(palette++) = screen->format->palette->colors[x].g;
   *(palette++) = screen->format->palette->colors[x].b;
   }

#else
  RGB8->get(palette,startcolor,endcolor);
#endif
}

void fade_palette_out(int startcolor, int endcolor, p_callback *pb)
{
  char rgb[PALETTE_SIZE];
  int i, j, max;
  get_palette(0,256,rgb);
  for (max = 63; max >= 0; max--)
    {
      if (!pb(max))
	break;
      for (i = startcolor; i <= endcolor; i++)
	{
	  /*
	   * Make each red, green, blue <= max
	   */
	  j = i * 3;
	  if (rgb[j] > max)
	    rgb[j] = max;
	  if (rgb[j+1] > max)
	    rgb[j+1] = max;
	  if (rgb[j+2] > max)
	    rgb[j+2] = max;
	}
      set_palette(startcolor,endcolor,rgb);
    }
}

void clr_palette(int start, int number)
{
  int i;
  if ((start>256) | (start<0) | ((start+number)>256))
    return;
  for (i=start;i<(start+number);i++)
    set_rgb_value(i,0,0,0);
}

extern int ch_clip(int *, Rect *);
void mline(int, int, int, int, char);

void b_linedraw(int x1, int y1, int x2, int y2, int color, Rect *bounds)
{
  if (bounds)
    {
      int points[4];
      points[0] = x1;
      points[1] = y1;
      points[2] = x2;
      points[3] = y2;
      if (!ch_clip(points,bounds))
	return;
      x1 = points[0];
      y1 = points[1];
      x2 = points[2];
      y2 = points[3];
    }
  mline(x1,y1,x2,y2,(char) color);
}

void mline(int x0, int y0, int x1, int y1, char color)
{
  DDALine dline(x0,y0,x1,y1);
  do
    {
      putpixel(dline.X(),dline.Y(),color);
    }
  while (dline.step());
}

#ifdef HAVE_LIBSDL
int FilterEvents(const SDL_Event *event)
{
  if(event->type == SDL_KEYDOWN)
    return 1;
  return 0;
}
#endif

/**********************************************************
 * From windows version (DirectX)                         *
 **********************************************************/

unsigned char *lock_xbuff()
{
  return (xbuffer);
}

void free_xbuff()
{

}

void vga13_suspend()
{

}

void vga13_resume()
{

}

void vga13_begin_scene()
{

}

void vga13_end_scene()
{

}


