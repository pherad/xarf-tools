/* This file is part of X-ARF tools.
 *
 * X-ARF tools is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * X-ARF tools is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see
 *
 *  http://www.gnu.org/licenses/
 *
 *
 * Copyright (c)
 *   2015-2017 Alexander Haase <ahaase@mksec.de>
 */

#ifndef LIBXARF_DYNAMIC_ENTITY_H
#define LIBXARF_DYNAMIC_ENTITY_H


#include <mimetic/message.h>


namespace xarf {

/** \brief TextPlain class with auto-switch to Base64.
 *
 * \details RFC822 recommends a maximum length of 78 characters per line. But
 *  Base64 needs more space to save the same data as plain text. This class
 *  switches the encoding from plain to Base64 automatically, if at least one
 *  line has more than 78 characters.
 */
class dynamicEntity : public mimetic::TextPlain
{
public:
  dynamicEntity();
  dynamicEntity(const std::string &text);

  void assign(const std::string &text);
  const std::string fetch() const;
};
}


#endif
