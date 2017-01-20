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

# This CMake module should help to organize the header files of libxarf. It
# provides functions to install public header files and variables to find the
# location of these files to pass these directories to include_directories.
#
# All this is done to provide a uniform interface for accessing the header
# files, which are spread all over the projects directories, as if they were
# installed at the platform if libxarf is installed. C++ files may then access
# them as #include <xarf/message.hpp> instead of searching the actual location of
# the message.hpp header file.

include(GNUInstallDirs)


# First we have to define a temporary location for all header files to copy them
# to this location, so all targets may simply include these path.
set(XARF_HEADER_DIR "${PROJECT_BINARY_DIR}/src/libxarf/header")


# Add a public header file.
#
# This function puts a copy of FILE into XARF_HEADER_DIR (into the xarf sub-
# directory to make #include <xarf/...> possible) and adds it to the install
# list.
function (xarf_add_header FILE)
	if (ARGV1)
		set(NAME ${ARGV1})
	else ()
		get_filename_component("NAME" ${FILE} NAME)
	endif ()

	configure_file(${FILE} "${XARF_HEADER_DIR}/xarf/${NAME}" COPYONLY)

	install(FILES "${XARF_HEADER_DIR}/xarf/${NAME}"
	        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/xarf")
endfunction ()
