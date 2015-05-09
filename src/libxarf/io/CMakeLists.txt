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


# search for required modules
find_package(Mimetic REQUIRED)


# activate CXX11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# include parent directory and mimetic include dir for header files.
include_directories(.. ${MIMETIC_INCLUDE_DIRS})

# build object library for io functions.
add_library(xarf_io OBJECT
	operator_out.cpp
)

set_property(TARGET xarf_io PROPERTY COMPILE_FLAGS "-fPIC")


# build object library for static io functions.
add_library(xarf_io_static OBJECT
	operator_out.cpp
)
