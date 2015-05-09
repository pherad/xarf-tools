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

#include <cstdint>
#include <mimetic/message.h>


std::ostream&
operator<< (std::ostream &out, const XARF &report)
{
	// create new multipart mail
	mimetic::MultipartMixed mail;

	// set MIME-preamble
	mail.body().preamble("This is a multi-part message in MIME format.");

	// set FROM-header
	mail.header().from(report.mail_from);


	// stream to out and return out
	out << mail;
	return out;
}
