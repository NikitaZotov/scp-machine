
#include <iostream>
#include "sc-memory/sc-memory/sc_addr.hpp"
#include "sc-memory/sc-memory/sc_object.hpp"
#include "sc-memory/sc-memory/kpm/sc_agent.hpp"
#include "sc-memory/sc-memory/sc_event.hpp"
#include "scp.hpp"
#include "scpKeynodes.hpp"
#include "scpProcessCreator.hpp"
#include "scpProcessDestroyer.hpp"
#include "scpGenOperatorInterpreter.hpp"
#include "scpEraseOperatorInterpreter.hpp"
#include "scpSearchOperatorInterpreter.hpp"
#include "scpIfOperatorInterpreter.hpp"
#include "scpVarValueOperatorInterpreter.hpp"
#include "scpPrintOperatorInterpreter.hpp"
#include "scpProgramExecutionSyncronizer.hpp"
#include "scpProcessControlOperatorInterpreter.hpp"
#include "scpMathOperatorInterpreter.hpp"
#include "scpStringOperatorInterpreter.hpp"
#include "scpAgentProcessor.hpp"
#include "scpAgentEvent.hpp"
#include "scpWaitEvent.hpp"
#include "scpFinishedInterpretationActionProcessor.hpp"

using namespace scp;

SC_IMPLEMENT_MODULE(scpModule)

std::unique_ptr<ScMemoryContext> scpModule::s_default_ctx;

sc_result scpModule::InitializeImpl()
{
    std::cout << "SCP START" << std::endl;

    if (!scp::Keynodes::InitGlobal())
        return SC_RESULT_ERROR;

    SC_AGENT_REGISTER(ASCPProcessCreator)
    SC_AGENT_REGISTER(ASCPProcessDestroyer)
    SC_AGENT_REGISTER(ASCPGenOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPEraseOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPSearchOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPIfOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPStringOperatorInterpreter);
    SC_AGENT_REGISTER(ASCPPrintOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPVarValueOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPProgramExecutionSyncronizer)
    SC_AGENT_REGISTER(ASCPProcessControlOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPAgentActivator)
    SC_AGENT_REGISTER(ASCPAgentDeactivator)
    SC_AGENT_REGISTER(ASCPFinishedInterpretationActionProcessor)
    SC_AGENT_REGISTER(ASCPMathOperatorInterpreter)
    SC_AGENT_REGISTER(ASCPStringOperatorInterpreter)

    s_default_ctx.reset(new ScMemoryContext(sc_access_lvl_make_min));
    SCPAgentEvent::register_all_scp_agents(s_default_ctx);

    return SC_RESULT_OK;
}

sc_result scpModule::ShutdownImpl()
{
    std::cout << "SCP END" << std::endl;

    SC_AGENT_UNREGISTER(ASCPProcessCreator)
    SC_AGENT_UNREGISTER(ASCPProcessDestroyer)
    SC_AGENT_UNREGISTER(ASCPGenOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPEraseOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPSearchOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPIfOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPVarValueOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPPrintOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPProgramExecutionSyncronizer)
    SC_AGENT_UNREGISTER(ASCPProcessControlOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPAgentActivator)
    SC_AGENT_UNREGISTER(ASCPAgentDeactivator)
    SC_AGENT_UNREGISTER(ASCPMathOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPStringOperatorInterpreter)
    SC_AGENT_UNREGISTER(ASCPFinishedInterpretationActionProcessor)

    SCPAgentEvent::unregister_all_scp_agents();
    SCPWaitEvent::unregister_all_sys_wait();
    s_default_ctx.reset();

    return SC_RESULT_OK;
}
