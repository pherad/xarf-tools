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
find_package(MIMETIC REQUIRED)

# include header files
include_directories(${MIMETIC_INCLUDE_DIRS})

# build library
add_lib(xarf
	$<TARGET_OBJECTS:xarf_header>
	$<TARGET_OBJECTS:xarf_io>
)

# link library against mimetic
target_link_libraries(xarf_static ${MIMETIC_LIBRARIES})
target_link_libraries(xarf_shared ${MIMETIC_LIBRARIES})
