// $Id: EditorGroundpieceObj.hh,v 1.3 2001/08/11 18:53:39 grumbel Exp $
//
// Pingus - A free Lemmings clone
// Copyright (C) 1999 Ingo Ruhnke <grumbel@gmx.de>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef PSMOBJ_HH
#define PSMOBJ_HH

#include <cstdio>
#include "SpriteEditorObj.hh"
#include "../GroundpieceData.hh"

///
class EditorGroundpieceObj : public GroundpieceData,
			     public SpriteEditorObj
{
public:
  EditorGroundpieceObj(const GroundpieceData& data);

  void write_xml(std::ofstream* xml) { GroundpieceData::write_xml (xml); }
  boost::shared_ptr<EditorObj> duplicate();
  std::string status_line();
};

#endif

/* EOF */


