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

include(GNUInstallDirs)


# Options
#
option("BUILD_DOC" "Build HTML documentation" Off)
option("BUILD_DOC_INTERNAL"
  "Build HTML documentation including private functions" Off)

if (NOT BUILD_DOC AND NOT BUILD_DOC_INTERNAL)
  return()
endif ()


# Configuration
#
find_package(Doxygen REQUIRED)

if (NOT DOXYGEN_DOT_EXECUTABLE)
  set(DOXYGEN_DOT_EXECUTABLE "")
endif ()

set(DOXYGEN_DOC_INTERNAL "NO")
if (BUILD_DOC_INTERNAL)
  set(DOXYGEN_DOC_INTERNAL "YES")
endif ()

configure_file(doxygen.conf.in doxygen.conf @ONLY)


# Build documentation
#
set(doxygen_html_index ${CMAKE_CURRENT_BINARY_DIR}/html/index.html)
set(doxygen_config ${CMAKE_CURRENT_BINARY_DIR}/doxygen.conf)

add_custom_command(OUTPUT ${doxygen_html_index}
  COMMAND ${DOXYGEN_EXECUTABLE} ${doxygen_config}
  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
  MAIN_DEPENDENCY ${doxygen_config}
  DEPENDS xarf_shared
  COMMENT "Generating documentation"
)
add_custom_target(doc ALL DEPENDS ${doxygen_html_index})


# install documentation
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
        DESTINATION ${CMAKE_INSTALL_DOCDIR})
