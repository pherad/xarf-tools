/* This file is part of X-ARF tools.
 *
 * X-ARF tools is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License and GNU
 * Lesser General Public License along with this program. If not, see
 *
 * http://www.gnu.org/licenses/
 *
 *
 * Copyright (C)
 *  2015 Alexander Haase <alexander.haase@rwth-aachen.de>
 */


#include "xarf.hpp"


/** \brief Set \p text as text for send mail.
 *
 * \details Copies string \p text into internal memory and sets it as text for
 *  the generated mail.
 *
 *
 * \param text Plain text for mail.
 *
 * \return This function returns no value.
 *
 * \exception If \p text would exceed the internal strings max_size, a
 *  length_error exception is thrown.
 * \exception A bad_alloc exception is thrown if the function needs to allocate
 *  storage and fails.
 */
void
XARF::set_message_body(std::string &text)
{
	this->mail_body = text;
}
