/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#pragma once

#include "sc-memory/sc-memory/sc_addr.hpp"
#include "sc-memory/sc-memory/sc_object.hpp"
#include "sc-memory/sc-memory/kpm/sc_agent.hpp"
#include "scpKeynodes.hpp"
#include "scpOperatorStr.hpp"

namespace scp
{

class SCPOperatorIfCoin: public SCPOperatorElStr2
{
public:
    SCPOperatorIfCoin(const std::unique_ptr<ScMemoryContext> &ctx, ScAddr addr);
    std::string GetTypeName();
    sc_result Parse();
    sc_result Execute();
};

}

