//  $Id: ConveyorBelt.hh,v 1.16 2001/08/10 19:59:20 grumbel Exp $
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

#ifndef CONVEYORBELT_HH
#define CONVEYORBELT_HH

#include <ClanLib/core.h>
#include "../WorldObj.hh"
#include "../WorldObjData.hh"
#include "../editor/EditorWorldObj.hh"

class ConveyorBeltData : public WorldObjData
{
public:
  CL_Vector pos;
  int width;
  double speed;

  ConveyorBeltData ();

  /** Write the content of this object formatted as xml to the given
      stream */
  void write_xml(std::ofstream* xml);
  ///
  static boost::shared_ptr<WorldObjData> create(xmlDocPtr doc, xmlNodePtr cur);

  /** Create an WorldObj from the given data object */
  boost::shared_ptr<WorldObj> create_WorldObj ();

  /** Create an EditorObj from the given data object */
  std::list<boost::shared_ptr<EditorObj> > create_EditorObj ();
};

class ConveyorBelt : private ConveyorBeltData,
		     public  WorldObj
{
private:
  CL_Surface left_sur;
  CL_Surface right_sur;
  CL_Surface middle_sur;
  float counter;

public:
  ConveyorBelt (WorldObjData*);
  
  void draw_offset (int x_of, int y_of, float s = 1.0);
  void draw_colmap();
  void update(float delta);
  int  get_z_pos() const { return (int) pos.z; }
};

class EditorConveyorBeltObj : public EditorWorldObj,
			      public ConveyorBeltData
{
private:
  CL_Surface left_sur;
  CL_Surface right_sur;
  CL_Surface middle_sur;
  float counter;

public:
  EditorConveyorBeltObj (WorldObjData* obj);

  boost::shared_ptr<EditorObj> duplicate();
  void draw (boost::dummy_ptr<EditorView> view);
  void draw_scroll_map(int x_pos, int y_pos, int arg_width, int arg_height);
  
  /// The saving will be done in EditorTeleporterObj::save_xml
  static std::list<boost::shared_ptr<EditorObj> > create (WorldObjData* obj);

  /** Create the object with reasonable defaults */
  static std::list<boost::shared_ptr<EditorObj> > create (const CL_Vector& pos);

  void save_xml (std::ofstream* xml);
  std::string status_line();
};

#endif

/* EOF */
