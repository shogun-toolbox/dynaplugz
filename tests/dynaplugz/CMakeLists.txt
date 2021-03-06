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

include( ProcessorCount )
ProcessorCount( TESTJOBS )
MATH( EXPR TESTJOBS "${TESTJOBS} + 1" )

add_executable(
  get_instance
    "get_instance.cpp"
)

target_link_libraries(
  get_instance
    ${PROJECT_NAME}
)

add_dependencies(
  get_instance
    ${PROJECT_NAME}
)

add_custom_target(
  test_binaries
    DEPENDS
      get_instance
)

add_test(
  NAME
    "get_and_compare_CDynaplugz_instances"
  COMMAND
    "get_instance"
)

add_custom_target(
  check
    COMMAND
      ${CMAKE_CTEST_COMMAND} -j${TESTJOBS} -V
    WORKING_DIRECTORY
      ${CMAKE_BINARY_DIR}
    DEPENDS
      test_binaries
)

add_custom_target(
  memcheck
    COMMAND
      ${CMAKE_CTEST_COMMAND} -D ExperimentalMemCheck -j${TESTJOBS} -V
    WORKING_DIRECTORY
      ${CMAKE_BINARY_DIR}
    DEPENDS
      test_binaries
)
