//  $Id: starfield_background_stars.cxx,v 1.8 2003/06/17 14:09:20 grumbel Exp $
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2000 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "../gui/graphic_context.hxx"
#include "../world.hxx"
#include "../pingus_resource.hxx"
#include "starfield_background_stars.hxx"

namespace WorldObjs {

StarfieldBackgroundStars::StarfieldBackgroundStars (Type type)
{
  switch (type)
    {
    case SMALL_STAR:
      sur = PingusResource::load_surface("Stars/small_star" , "game");
      break;
    case MIDDLE_STAR:
      sur = PingusResource::load_surface("Stars/middle_star", "game");
      break;
    case LARGE_STAR:
      sur = PingusResource::load_surface("Stars/large_star" , "game");
      break;
    }

  x_pos = rand() % WorldObj::get_world()->get_width();
  y_pos = rand() % WorldObj::get_world()->get_height();

  x_add = rand() % 5 + 1.0f;
  y_add = 0.0f;
}

void
StarfieldBackgroundStars::update ()
{
  x_pos += x_add;
  y_pos += y_add;

  if (x_pos > WorldObj::get_world()->get_width())
    {
      x_pos = -32;
      y_pos = rand() % WorldObj::get_world()->get_height();
    }
}

void
StarfieldBackgroundStars::draw (GraphicContext& gc)
{
  gc.draw(sur, Vector (x_pos, y_pos));
}

} // namespace WorldObjs

/* EOF */