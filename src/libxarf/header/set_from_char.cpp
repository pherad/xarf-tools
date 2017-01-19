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


#include "xarf.hpp"


/** \brief Set \p mail_address as from-header for send mail.
 *
 * \details Copies array of char \p mail_address into internal memory and sets
 *  it as from-header for the generated mail.
 *
 *
 * \param mail_address Mail-address as defined in RFC 822.
 *
 * \return This function returns no value.
 *
 * \exception If \p mail_address would exceed the internal strings max_size, a
 *  length_error exception is thrown.
 * \exception A bad_alloc exception is thrown if the function needs to allocate
 *  storage and fails.
 */
void
XARF::set_from(const char* mail_address)
{
	this->mail_from = mail_address;
}
