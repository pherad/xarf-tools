# This file is part of X-ARF tools.
#
# X-ARF tools is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# X-ARF tools is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see
#
#  http://www.gnu.org/licenses/
#
#
# Copyright (c)
#   2015-2017 Alexander Haase <ahaase@mksec.de>
#

include(easylib)
include(xarf_headers)

find_package(MIMETIC REQUIRED)


# Include directories required for all parts of libXARF.
include_directories(${MIMETIC_INCLUDE_DIRS}
                    ${XARF_HEADER_DIR})


# Recurse into subdirectories.
#
# This has to be done BEFORE adding the X-ARF libraries, because for adding
# X-ARF with its object libraries, the easylib functions need to know about the
# available object libraries. Otherwise the compilation of libxarf will result
# in errors, as easylib would select the static object library for the shared
# X-ARF library.
add_subdirectory(dynamic_entity)
add_subdirectory(message)


#
# build libXARF
#

easy_add_library(xarf
  $<TARGET_OBJECTS:xarf_dynamic_entity>
  $<TARGET_OBJECTS:xarf_message>)

target_link_libraries(xarf_shared ${MIMETIC_LIBRARIES})
