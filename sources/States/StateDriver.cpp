#include <States/StateDriver.h>

void StateDriver::PushState(IStatePtr state)
{
	m_stateStack.push_back(state);
	state->Execute();
}