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

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/config.hpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.hpp"
    @ONLY
)

file(
  MAKE_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}"
)

set(
  DYNAPLUGZ_SOURCES
    dynaplugz.cpp
)

set(
  DYNAPLUGZ_HEADERS
    "${CMAKE_CURRENT_BINARY_DIR}/config.hpp"
    dynaplugz.hpp
)

add_library(
  ${PROJECT_NAME}
    ${DYNAPLUGZ_SOURCES}
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
    PUBLIC_HEADER  "${DYNAPLUGZ_HEADERS}"
    SOVERSION      "${PROJECT_SOVER}"
)

install(
  TARGETS
    ${PROJECT_NAME}
  EXPORT
    DynaplugzTargets
  LIBRARY DESTINATION
    "${LIB_INSTALL_DIR}"
  PUBLIC_HEADER DESTINATION
    "${INCLUDE_INSTALL_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}${PROJECT_VERSION_GIT}/${PROJECT_NAME}"
)

install(
  DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}"
  DESTINATION
    "${LIB_INSTALL_DIR}"
)

export(
  TARGETS
    ${PROJECT_NAME}
  FILE
    "${CMAKE_CURRENT_BINARY_DIR}/DynaplugzTargets.cmake"
)

install(
  EXPORT
    DynaplugzTargets
  DESTINATION
    "${TARGETCONF_INSTALL_DIR}"
)
