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

#include <cstdint>
#include <mimetic/message.h>


std::ostream&
operator<< (std::ostream &out, const XARF &report)
{
	// create new multipart mail
	mimetic::MultipartMixed mail;

	// set mail header
	mail.header().from(report.mail_from);
	mail.header().to(report.mail_to);

	// set MIME-preamble
	mail.body().preamble("This is a multi-part message in MIME format.");


	// write message body
	mimetic::TextPlain *msg_body = new mimetic::TextPlain(report.mail_body);
	mail.body().parts().push_back(msg_body);

	// stream to out and return out
	out << mail;
	return out;
}
