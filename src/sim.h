/*
    SABRE Fighter Plane Simulator 
    Copyright (c) 1997 Dan Hammer
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
#ifndef __sim_h
#define __sim_h
#include <stdlib.h>

extern float world_scale;
extern float time_factor;
extern float time_frame;
extern float hit_scaler;
extern float shape_scaler;
extern float player_hit_scaler;

#include "rtkey.h"

#pragma warning ( 4 : 4136 )
#pragma warning ( 4 : 4244 )
#pragma warning ( 4 : 4305 )

#ifndef SABREWIN
#define __cdecl 
#endif

inline int RANDOM(int x) 
{
  return (rand() % (x));
}

inline long coreleft()
{
  return (100000L);
}

// convert knots to feet per second
inline float kts2fps(float kts)
{
  return ((kts / 3600.0) * 6000.0);
}
// convert feet per second to knots
inline float fps2kts(float fps)
{
  return ((fps * 3600.0) / 6000.0);
}
// convert miles per hour to feet per second
inline float mph2fps(float mph)
{
  return ((mph / 3600.0) * 5280.0);
}
// convert feet per second to miles per hour
inline float fps2mph(float fps)
{
  return ((fps * 3600.0) / 5280.0);
}
// convert miles to feet
inline float m2f(float m)
{
  return (m * 5280.0);
}
// convert feet to miles
inline float f2m(float f)
{
  return (f / 5280.0);
}

#define INT_PERC(x) (((float)x) / 100.0)

inline float frand(float val)
{
  float d = INT_PERC(RANDOM(100));
  return (d * val);

}
#endif
