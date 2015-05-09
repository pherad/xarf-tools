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
# recurse into subdirectories
#
add_subdirectory(header)
add_subdirectory(io)


#
# build libXARF
#

# search for required modules
find_package(Mimetic REQUIRED)

# include header files
include_directories(${MIMETIC_INCLUDE_DIRS})


# build dynamic library
add_library(xarf SHARED
	$<TARGET_OBJECTS:xarf_header>
	$<TARGET_OBJECTS:xarf_io>
)

# link dynamic library against mimetic
target_link_libraries(xarf ${MIMETIC_LIBRARIES})


# build static library
add_library(xarf_static STATIC
	$<TARGET_OBJECTS:xarf_header_static>
	$<TARGET_OBJECTS:xarf_io_static>
)

# set output name of xarf_static to xarf
set_target_properties(xarf_static PROPERTIES OUTPUT_NAME xarf)

# link static library against mimetic
target_link_libraries(xarf_static ${MIMETIC_LIBRARIES})
