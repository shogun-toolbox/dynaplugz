##
## -*- coding: utf-8 -*-
## vim: set fileencoding=utf-8
##
## Copyright (c) 2016, Shogun-Toolbox e.V. <shogun-team@shogun-toolbox.org>
## All rights reserved.
##
## Redistribution and use in source and binary forms, with or without
## modification, are permitted provided that the following conditions are met:
##
##  1. Redistributions of source code must retain the above copyright notice,
##     this list of conditions and the following disclaimer.
##
##  2. Redistributions in binary form must reproduce the above copyright
##     notice, this list of conditions and the following disclaimer in the
##     documentation and/or other materials provided with the distribution.
##
##  3. Neither the name of the copyright holder nor the names of its
##     contributors may be used to endorse or promote products derived from
##     this software without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
## IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
## ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
## LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
## CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
## SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
## INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
## CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
## POSSIBILITY OF SUCH DAMAGE.
##
## Authors: 2016, Björn Esser <me@besser82.io>
##

find_program( RPM_EXECUTABLE rpm )

if( RPM_EXECUTABLE )
  execute_process(
    COMMAND
      "${RPM_EXECUTABLE}" --version
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    OUTPUT_VARIABLE
      RPM_VERSION
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  string(
    REGEX REPLACE ".*[ \t]\+" ""
      RPM_VERSION "${RPM_VERSION}"
  )

  message(
    STATUS
      "Found RPM: ${RPM_EXECUTABLE} (found version \"${RPM_VERSION}\")"
      )

  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/macros.${PROJECT_NAME}.in"
    "${CMAKE_CURRENT_BINARY_DIR}/macros.${PROJECT_NAME}"
      @ONLY
  )

  execute_process(
    COMMAND
      "${RPM_EXECUTABLE}" -E %{_rpmconfigdir}
    WORKING_DIRECTORY
      "${CMAKE_CURRENT_BINARY_DIR}"
    OUTPUT_VARIABLE
      RPM_CONFIG_DIR
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
  )

  if( NOT RPMMACROS_INSTALL_DIR )
    set(
      RPMMACROS_INSTALL_DIR
        "${RPM_CONFIG_DIR}/macros.d"
    )
  endif( NOT RPMMACROS_INSTALL_DIR )

  install(
    FILES
      "${CMAKE_CURRENT_BINARY_DIR}/macros.${PROJECT_NAME}"
    DESTINATION
      "${RPMMACROS_INSTALL_DIR}"
  )
endif( RPM_EXECUTABLE )

# Check which C++11-flag is needed.
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" HAVE_CXX11_FLAG)

if( HAVE_CXX11_FLAG )
  set( USED_CXX11_FLAG "-std=c++11 " )
else( HAVE_CXX11_FLAG )
  CHECK_CXX_COMPILER_FLAG("-std=c++0x" HAVE_CXX0X_FLAG)
  if( HAVE_CXX0X_FLAG )
    set( USED_CXX11_FLAG "-std=c++0x " )
  endif( HAVE_CXX0X_FLAG )
endif( HAVE_CXX11_FLAG )

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/dynaplugz.pc.in"
  "${CMAKE_CURRENT_BINARY_DIR}/dynaplugz.pc"
    @ONLY
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/dynaplugz.pc"
  DESTINATION
    "${LIB_INSTALL_DIR}/pkgconfig"
)

file(
  RELATIVE_PATH
    REL_INCLUDE_DIR
      "${TARGETCONF_INSTALL_DIR}"
      "${INCLUDE_INSTALL_DIR}"
)

set(
  CONF_INCLUDE_DIRS
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_BINARY_DIR}"
)

# Export target-config for use in build-tree.
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/DynaplugzConfig.cmake.in"
  "${PROJECT_BINARY_DIR}/DynaplugzConfig.cmake"
  @ONLY
)

set(
  CONF_INCLUDE_DIRS
    "\${DYNAPLUGZ_CMAKE_DIR}/${REL_INCLUDE_DIR}"
)

# Export target-config for system-wide use.
configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/DynaplugzConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/DynaplugzConfig.cmake"
    @ONLY
)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/DynaplugzConfigVersion.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/DynaplugzConfigVersion.cmake"
    @ONLY
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/DynaplugzConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/DynaplugzConfigVersion.cmake"
  DESTINATION
    "${TARGETCONF_INSTALL_DIR}"
)
