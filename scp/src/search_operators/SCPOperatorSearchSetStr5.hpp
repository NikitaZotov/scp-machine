/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

#include "sc-memory/sc_addr.hpp"
#include "sc-memory/sc_object.hpp"
#include <sc-memory/sc_agent.hpp>
#include "scpKeynodes.hpp"
#include "scpOperatorSet.hpp"

namespace scp
{

class SCPOperatorSearchSetStr5 : public SCPOperatorSetStr5
{
public:
  SCPOperatorSearchSetStr5(ScAgentContext & ctx, ScAddr addr);
  std::string GetTypeName();
  sc_result Parse();
  sc_result Execute();
};

}  // namespace scp
