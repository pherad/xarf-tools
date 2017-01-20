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

#ifndef LIBXARF_MESSAGE_H
#define LIBXARF_MESSAGE_H


#include <iostream>

#include <mimetic/mimeentity.h>


namespace xarf {

/** \brief Class for handling the X-ARF report as mail.
 *
 * \details This class is a special mimetic MimeEntity class to emit and parse
 *  X-ARF mails. MimeEntity provides the basic structure of the mail, while this
 *  class is responsible for the structure of the mail and its attachments.
 *
 * \note MultipartMixed can't be used due its incompatibility for parsing mails.
 *  It will generate new mails every time a constructor is called.
 */
class message : public mimetic::MimeEntity
{
public:
  message();
  message(std::istream &);
};
}


#endif
