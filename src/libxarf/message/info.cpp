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

#include <xarf/message.hpp>


using xarf::message;
using xarf::dynamicEntity;


/** \brief Get the first MIME part.
 *
 * \details The first MIME part is a human readable info message about what
 *  happened.
 *
 *
 * \return Pointer to the first MIME part.
 */
dynamicEntity *
message::info()
{
  return (dynamicEntity *)*(m_body.parts().begin());
}
