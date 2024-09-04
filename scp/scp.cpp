
#include "scp.hpp"
#include "scpAgentEvent.hpp"
#include "scpAgentProcessor.hpp"
#include "scpEraseOperatorInterpreter.hpp"
#include "scpFinishedInterpretationActionProcessor.hpp"
#include "scpGenOperatorInterpreter.hpp"
#include "scpIfOperatorInterpreter.hpp"
#include "scpKeynodes.hpp"
#include "scpMathOperatorInterpreter.hpp"
#include "scpPrintOperatorInterpreter.hpp"
#include "scpProcessControlOperatorInterpreter.hpp"
#include "scpProcessCreator.hpp"
#include "scpProcessDestroyer.hpp"
#include "scpProgramExecutionSyncronizer.hpp"
#include "scpSearchOperatorInterpreter.hpp"
#include "scpStringOperatorInterpreter.hpp"
#include "scpVarValueOperatorInterpreter.hpp"
#include "scpWaitEvent.hpp"

#include <sc-memory/sc_agent.hpp>

#include <iostream>

using namespace scp;

SC_MODULE_REGISTER(scpModule)
  ->Agent<ASCPProcessCreator>()
  ->Agent<ASCPProcessDestroyer>()
  ->Agent<ASCPGenOperatorInterpreter>()
  ->Agent<ASCPEraseOperatorInterpreter>()
  ->Agent<ASCPSearchOperatorInterpreter>()
  ->Agent<ASCPIfOperatorInterpreter>()
  ->Agent<ASCPVarValueOperatorInterpreter>()
  ->Agent<ASCPPrintOperatorInterpreter>()
  ->Agent<ASCPProgramExecutionSyncronizer>()
  ->Agent<ASCPProcessControlOperatorInterpreter>()
  ->Agent<ASCPAgentActivator>()
  ->Agent<ASCPAgentDeactivator>()
  ->Agent<ASCPMathOperatorInterpreter>()
  ->Agent<ASCPStringOperatorInterpreter>()
  ->Agent<ASCPFinishedInterpretationActionProcessor>()
  ->Agent<ASCPProcessCreator>()
  ->Agent<ASCPProcessDestroyer>()
  ->Agent<ASCPGenOperatorInterpreter>()
  ->Agent<ASCPEraseOperatorInterpreter>()
  ->Agent<ASCPSearchOperatorInterpreter>()
  ->Agent<ASCPIfOperatorInterpreter>()
  ->Agent<ASCPVarValueOperatorInterpreter>()
  ->Agent<ASCPPrintOperatorInterpreter>()
  ->Agent<ASCPProgramExecutionSyncronizer>()
  ->Agent<ASCPProcessControlOperatorInterpreter>()
  ->Agent<ASCPAgentActivator>()
  ->Agent<ASCPAgentDeactivator>()
  ->Agent<ASCPMathOperatorInterpreter>()
  ->Agent<ASCPStringOperatorInterpreter>()
  ->Agent<ASCPFinishedInterpretationActionProcessor>();

ScMemoryContext scpModule::s_default_ctx;

void scpModule::Initialize(ScMemoryContext * context)
{
  ScModule::Initialize(context);
  std::cout << "SCP START" << std::endl;
  SCPAgentEvent::register_all_scp_agents(s_default_ctx);
}

void scpModule::Shutdown(ScMemoryContext * context)
{
  ScModule::Shutdown(context);
  std::cout << "SCP END" << std::endl;

  SCPAgentEvent::unregister_all_scp_agents(s_default_ctx);
  SCPWaitEvent::unregister_all_sys_wait();
}
