#include <States/StateDriver.h>

void StateDriver::PushState(IStatePtr state)
{
	if (!m_stateStack.empty())
	{
		m_stateStack.back()->Suspend();
	}
	m_stateStack.push_back(state);
	state->Execute();
}