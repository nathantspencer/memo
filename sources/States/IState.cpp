#include "IState.h"

IState::IState(std::function<void()> terminateHandler, std::function<void(IStatePtr)> addChildStateHandler) :
	m_terminateHandler(terminateHandler),
	m_addChildStateHandler(addChildStateHandler)
{
}

void IState::Terminate()
{
	m_terminateHandler();
}

void IState::AddChildState(IStatePtr childState)
{
	m_addChildStateHandler(childState);
}
