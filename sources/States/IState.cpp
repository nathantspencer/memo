#include "IState.h"

void IState::SetTerminateHandler(std::function<void()> terminateHandler)
{
	m_terminateHandler = terminateHandler;
}

void IState::SetAddChildStateHandler(std::function<void(IStatePtr)> addChildStateHandler)
{
	m_addChildStateHandler = addChildStateHandler;
}

void IState::Terminate()
{
	if (m_terminateHandler)
	{
		m_terminateHandler();
	}
}

void IState::AddChildState(IStatePtr childState)
{
	if (m_addChildStateHandler)
	{
		m_addChildStateHandler(childState);
	}
}
