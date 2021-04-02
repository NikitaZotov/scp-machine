/*
* This source file is part of an OSTIS project. For the latest info, see http://ostis.net
* Distributed under the MIT License
* (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
*/

#include "scpKeynodes.hpp"
#include "scpUtils.hpp"
#include "SCPOperatorGenEl.hpp"
#include "sc-memory/sc-memory/sc_memory.hpp"
#include <iostream>

namespace scp
{

//genEl
SCPOperatorGenEl::SCPOperatorGenEl(const std::unique_ptr<ScMemoryContext> &ctx, ScAddr addr): SCPOperatorElStr1(ctx, addr)
{
}

std::string SCPOperatorGenEl::GetTypeName()
{
    return "genEl";
}

sc_result SCPOperatorGenEl::Parse()
{
    return SCPOperatorElStr1::Parse();
}

sc_result SCPOperatorGenEl::Execute()
{
    if (SC_RESULT_OK != ResetValues())
        return SC_RESULT_ERROR;

    if (operands[0]->IsFixed())
    {
#ifdef SCP_DEBUG
        Utils::logSCPError(ms_context, "Operand must have ASSIGN modifier", addr);
#endif
        FinishExecutionWithError();
        return SC_RESULT_ERROR_INVALID_PARAMS;
    }

    operands[0]->CreateNodeOrLink();

    FinishExecutionSuccessfully();
    return SC_RESULT_OK;
}
}
