//  $Id: pingu_action_factory.hxx,v 1.3 2002/06/28 15:12:22 torangan Exp $
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

#ifndef HEADER_PINGUS_PINGU_ACTION_FACTORY_HXX
#define HEADER_PINGUS_PINGU_ACTION_FACTORY_HXX

#include <map>
#include <string>
#include "pingu.hxx"

class PinguActionAbstractFactory;

class PinguActionFactory
{
private:
  /** This vector saves all allocated actions to delete them at a later point */
  std::vector<PinguAction*> all_actions;

  std::map<ActionName, PinguActionAbstractFactory*> factories;
  static PinguActionFactory* instance_;
  
  PinguActionFactory ();
  void register_core_actions ();
  
public:
  static PinguActionFactory* instance ();
  void register_factory (ActionName id, PinguActionAbstractFactory*);

  /** Delete all actions which this class has allocated. This needs to
      be called seperatly from the constructor, due to the used
      singleton pattern. [FIXME] */
  void delete_actions ();

  /** Allocate the given action */
  PinguAction* create (ActionName id);
};

class PinguActionAbstractFactory
{
public:
  PinguActionAbstractFactory (ActionName id) {
    PinguActionFactory::instance ()-> register_factory (id, this);
  }
  
  virtual PinguAction* create () =0;
};

template<class T>
class PinguActionFactoryImpl : public PinguActionAbstractFactory
{
public:
  PinguActionFactoryImpl (ActionName id)
    : PinguActionAbstractFactory (id)
  {
  }

  PinguAction* create () {
    return new T ();
  }
};

#endif

/* EOF */
