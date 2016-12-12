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

CMAKE_OPTIONS  = "-DCMAKE_VERBOSE_MAKEFILE=OFF"

all: configure build memcheck

build: configure
	$(MAKE) -C build ;

check: build
	$(MAKE) -C build check;

clean:
	rm -fr build ;

configure: clean
	mkdir -p build;
	cd build && \
	cmake $(CMAKE_OPTIONS) ..;

memcheck: build
	$(MAKE) -C build memcheck;
