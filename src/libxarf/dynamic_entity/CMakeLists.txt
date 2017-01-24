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

include(xarf_headers)


# Install and manage the public header files of the libxarf sources. This has to
# be done to use the same headers for the XARF sources and the API without
# getting conflicts about the used paths. Otherwise you'd have to take care
# about file locations after installation, especially if you use the headers
# over multiple directories.
xarf_add_header(dynamicEntity.hpp)


# Build libxarf dynamic entity module.
easy_add_library(xarf_dynamic_entity OBJECT
  dynamicEntity.cpp)
