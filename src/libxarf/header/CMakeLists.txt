# This file is part of X-ARF tools.
#
# X-ARF tools is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
# more details.
#
# You should have received a copy of the GNU General Public License and GNU
# Lesser General Public License along with this program. If not, see
#
# http://www.gnu.org/licenses/
#
#
# Copyright (C)
#   2015 Alexander Haase <alexander.haase@rwth-aachen.de>
#


#
# include required modules
#
include(add_lib)


#
# build libXARF header functions
#

# include parent directory for header files
include_directories(..)

# build object library for header functions
add_lib(xarf_header OBJECT
	set_from_char.cpp
	set_from_string.cpp

	set_to_char.cpp
	set_to_string.cpp

	set_message_body_char.cpp
	set_message_body_string.cpp
)
