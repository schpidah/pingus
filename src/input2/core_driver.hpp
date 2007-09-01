/*  $Id$
**   __      __ __             ___        __   __ __   __
**  /  \    /  \__| ____    __| _/_______/  |_|__|  | |  |   ____
**  \   \/\/   /  |/    \  / __ |/  ___/\   __\  |  | |  | _/ __ \
**   \        /|  |   |  \/ /_/ |\___ \  |  | |  |  |_|  |_\  ___/
**    \__/\  / |__|___|  /\____ /____  > |__| |__|____/____/\___  >
**         \/          \/      \/    \/                         \/
**  Copyright (C) 2007 Ingo Ruhnke <grumbel@gmx.de>
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation; either version 2
**  of the License, or (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
** 
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
**  02111-1307, USA.
*/

#ifndef HEADER_CORE_DRIVER_HPP
#define HEADER_CORE_DRIVER_HPP

namespace Input {

/** */
class CoreDriver : public Driver
{
private:

public:
  CoreDriver() {}
  virtual ~CoreDriver() {}

  std::string get_name() { return "core"; }
  void update(float delta) {}

  Button*   create_button  (const FileReader& reader, Control* parent) { return 0; }
  Axis*     create_axis    (const FileReader& reader, Control* parent) { return 0; }
  Scroller* create_scroller(const FileReader& reader, Control* parent) { return 0; }  
  Pointer*  create_pointer (const FileReader& reader, Control* parent) { return 0; }  
};

} // namespace Input

#endif

/* EOF */
