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


#ifndef LIBXARF_H
#define LIBXARF_H


#include <iostream>
#include <string>


class XARF
{
	public:
		friend std::ostream& operator<< (std::ostream &out, const XARF &report);
		//friend std::istream& operator>> (std::istream &in, XARF &report);

		void set_from(const char *mail_address);
		void set_from(std::string &mail_address);

		void set_to(const char *mail_address);
		void set_to(std::string &mail_address);

		void set_message_body(const char *src);
		void set_message_body(std::string &src);

	private:
		std::string mail_from;
		std::string mail_to;
		std::string mail_body;
};


#endif
