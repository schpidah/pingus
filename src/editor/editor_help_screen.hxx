//  $Id: editor_help_screen.hxx,v 1.6 2003/04/19 10:23:18 torangan Exp $
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

#ifndef HEADER_PINGUS_EDITOR_EDITOR_HELP_SCREEN_HXX
#define HEADER_PINGUS_EDITOR_EDITOR_HELP_SCREEN_HXX

#include "../pingus.hxx"

class CL_Font;

class EditorHelpScreen
{
private:
  CL_Font* font;
  CL_Font* large_font;
public:
  EditorHelpScreen ();
  void draw ();
  void update (float delta);

private:
  EditorHelpScreen (const EditorHelpScreen&);
  EditorHelpScreen& operator= (const EditorHelpScreen&);
};

#endif

/* EOF */