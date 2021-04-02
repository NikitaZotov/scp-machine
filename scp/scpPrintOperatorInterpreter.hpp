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

#include "scpPrintOperatorInterpreter.generated.hpp"

namespace scp
{

class ASCPPrintOperatorInterpreter : public ScAgent
{
    SC_CLASS(Agent, Event(Keynodes::active_action, ScEvent::Type::AddOutputEdge))
    SC_GENERATED_BODY()

public:
    SC_PROPERTY(Keynode("sc_agent_of_scp_operator_print_interpreting"), ForceCreate)
    static ScAddr msAgentKeynode;

};

}

