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


# minimum required cmake version
cmake_minimum_required(VERSION 2.8.11)


#
# project information
#
if (${CMAKE_MAJOR_VERSION} EQUAL 3)
	project("X-ARF tools" LANGUAGES C CXX)
else ()
	project("X-ARF tools" C CXX)
endif ()


# choose new behaviour for CMP0042
# see http://www.cmake.org/cmake/help/v3.0/policy/CMP0042.html for more details
if (POLICY CMP0042)
	cmake_policy(SET CMP0042 NEW)
endif (POLICY CMP0042)


#
# cmake configuration
#
set(CMAKE_MODULE_PATH
	"${PROJECT_SOURCE_DIR}/cmake"
	"${PROJECT_SOURCE_DIR}/externals/CMake-easylib/cmake"
	${CMAKE_MODULE_PATH})


#
# recurse into subdirectories
#
add_subdirectory(doc)
add_subdirectory(src)
