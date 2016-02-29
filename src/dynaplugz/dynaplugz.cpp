/*
 * -*- coding: utf-8 -*-
 * vim: set fileencoding=utf-8
 *
 * Copyright (c) 2016, Shogun-Toolbox e.V. <shogun-team@shogun-toolbox.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *  3. Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: 2016, Björn Esser <me@besser82.io>
 */

#include <iostream>
#include <dynaplugz/dynaplugz.hpp>

namespace Dynaplugz
{
  class CDynaplugzData
  {
    public:
      CDynaplugzData()                                           = default;
      CDynaplugzData( const CDynaplugzData& )                    = delete;
     ~CDynaplugzData()                                           = default;
      const CDynaplugzData& operator = ( const CDynaplugzData& ) = delete;
  };

  CDynaplugz::CDynaplugz():
    data( new CDynaplugzData() )
  {
    /* TODO: Use logger for this. */
    std::cerr << std::endl << std::endl << "Dynaplugz " << DP_VERSION
              << DP_VERSION_GIT << " says \"Hello!\"." << "  Using API: "
              << DP_SOVER << std::endl << std::endl << std::endl
              << "Copyright (c) 2016, Shogun-Toolbox e.V. "
              << "<shogun-team@shogun-toolbox.org>" << std::endl
              << "All rights reserved." << std::endl << std::endl
              << "Redistribution and use in source and binary forms, with or "
              << "without" << std::endl << "modification, are permitted "
              << "provided that the " << std::endl << "following conditions "
              << "are met:" << std::endl << std::endl
              << "  1. Redistributions of source code must retain the above "
              << "copyright notice," << std::endl << "     this list of "
              << "conditions " << "and the following disclaimer." << std::endl
              << std::endl << "  2. Redistributions in binary form must "
              << "reproduce the above copyright" << std::endl
              << "     notice, this list of conditions and the following "
              << "disclaimer in the" << std::endl << "     documentation "
              << "and/or other materials provided with the distribution."
              << std::endl << std::endl << "  3. Neither the name of the "
              << "copyright holder nor the names of its" << std::endl
              << "     contributors may be used to endorse or promote "
              << "products derived from" << std::endl << "     this software "
              << "without specific prior written permission." << std::endl
              << std::endl << "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT "
              << "HOLDERS AND CONTRIBUTORS \"AS IS\"" << std::endl << "AND "
              << "ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT "
              << "LIMITED TO, THE" << std::endl << "IMPLIED WARRANTIES OF "
              << "MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE"
              << std::endl << "ARE DISCLAIMED.  IN NO EVENT SHALL THE "
              << "COPYRIGHT HOLDER OR CONTRIBUTORS BE" << std::endl
              << "LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, "
              << "EXEMPLARY, OR" << std::endl << "CONSEQUENTIAL DAMAGES "
              << "(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF" << std::endl
              << "SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR "
              << "PROFITS; OR BUSINESS" << std::endl << "INTERRUPTION) "
              << "HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN"
              << std::endl << "CONTRACT, STRICT LIABILITY, OR TORT "
              << "(INCLUDING NEGLIGENCE OR OTHERWISE)" << std::endl
              << "ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN "
              << "IF ADVISED OF THE"  << std::endl << "POSSIBILITY OF SUCH "
              << "DAMAGE." << std::endl << std::endl;
  }

  CDynaplugz& CDynaplugz::instance()
  {
   static CDynaplugz myInstance;
    return myInstance;
  }
}
