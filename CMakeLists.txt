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

# Setup CMake
cmake_minimum_required( VERSION 3.1 )
cmake_policy( SET CMP0048 NEW )

# Setup project
project(
  dynaplugz
  VERSION 0.0.0.0
)

set( PROJECT_SOVER_CUR "0" )
set( PROJECT_SOVER_REV "0" )
set( PROJECT_SOVER_AGE "0" )
set( PROJECT_SOVER
     "${PROJECT_SOVER_CUR}.${PROJECT_SOVER_REV}.${PROJECT_SOVER_AGE}" )
set( PROJECT_NAME_CAP  "Dynaplugz" )

# Configurable options.
option( BUILD_SHARED_LIBS "Build a shared library"     ON )
option( BUILD_TESTING     "Enable and build testsuite" ON )

# Strip trailing whitespace from env's compiler-flags.
string( STRIP "${CMAKE_C_FLAGS}"          CMAKE_C_FLAGS )
string( STRIP "${CMAKE_CXX_FLAGS}"        CMAKE_CXX_FLAGS )
string( STRIP "${CMAKE_EXE_LINKER_FLAGS}" CMAKE_EXE_LINKER_FLAGS )

# Require C++11 globally.
set( CMAKE_CXX_STANDARD    11 )
set( CXX_STANDARD_REQUIRED TRUE )
set( CMAKE_CXX_EXTENSIONS  FALSE )

# Enable CTest.
include(CTest)

# Setup install-dirs.
if( NOT LIB_INSTALL_DIR )
  set( LIB_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/lib" )

  # Do we build on a 64-Bits arch?
  get_property( LIB64 GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS )

  if( LIB64 )
    set( LIB_INSTALL_DIR "${LIB_INSTALL_DIR}64" )
  endif( LIB64 )
endif( NOT LIB_INSTALL_DIR )

if( NOT INCLUDE_INSTALL_DIR )
 set( INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/include")
endif( NOT INCLUDE_INSTALL_DIR )

if( NOT SHARE_INSTALL_PREFIX )
 set( SHARE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/share")
endif( NOT SHARE_INSTALL_PREFIX )

# Add git-commit to version.
if( EXISTS ${CMAKE_SOURCE_DIR}/.git/ )
  find_package( Git )
  if( GIT_FOUND )
    execute_process(
      COMMAND ${GIT_EXECUTABLE} log HEAD~1..HEAD --format=%h
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      OUTPUT_VARIABLE PROJECT_GIT_COMMIT
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    execute_process(
      COMMAND ${GIT_EXECUTABLE} log HEAD~1..HEAD --date=short --format=%cd
      WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
      OUTPUT_VARIABLE PROJECT_GIT_DATE
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE
    )

    string(
      REGEX REPLACE "-" ""
      PROJECT_GIT_DATE ${PROJECT_GIT_DATE}
    )

    string(
      CONCAT PROJECT_VERSION_GIT
      ".git" ${PROJECT_GIT_DATE}
      "." ${PROJECT_GIT_COMMIT}
    )
  endif( GIT_FOUND )
endif( EXISTS ${CMAKE_SOURCE_DIR}/.git/ )

# Set common include-dirs for compiler.
include_directories( BEFORE
  "${CMAKE_CURRENT_SOURCE_DIR}/src"
  "${CMAKE_CURRENT_BINARY_DIR}/src"
)

# Add the subdir to process.
add_subdirectory( src )

if( BUILD_TESTING )
  add_subdirectory( tests )
endif( BUILD_TESTING )

add_subdirectory( doc )

# Give some output after configuration.
foreach( COUNT RANGE 75 )
  set( SPACER "${SPACER}-" )
endforeach( COUNT RANGE 75 )

message( STATUS "" )
message( STATUS "${SPACER}" )
message( STATUS "" )
message( STATUS "${PROJECT_NAME_CAP} config-summary:" )
message( STATUS "" )
message( STATUS "CFLAGS:   ${CMAKE_C_FLAGS}" )
message( STATUS "CXXFLAGS: ${CMAKE_CXX_FLAGS}" )
message( STATUS "LDFLAGS:  ${CMAKE_EXE_LINKER_FLAGS}" )
message( STATUS "" )
message( STATUS "default Plugin-Path:   ${LIB_INSTALL_DIR}/${PROJECT_NAME}" )
message( STATUS "default Plugin-Suffix: ${CMAKE_SHARED_LIBRARY_SUFFIX}" )
message( STATUS "" )
message( STATUS "${SPACER}" )
message( STATUS "" )
