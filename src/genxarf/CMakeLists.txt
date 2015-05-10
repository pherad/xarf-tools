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
# search for required libraries
#
find_package(Mimetic)


#
# build genxarf
#

# include header files of libxarf
include_directories(../libxarf)

# build genxarf
add_executable(genxarf
	genxarf.cpp
)

# link againt libxarf
target_link_libraries(genxarf xarf)
