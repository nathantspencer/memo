#include "IState.h"

IState::IState()
{
}

IState::IState(std::function<void()> terminateCallback) :
	m_terminateCallback(terminateCallback)
{
}

void IState::SetIsSuspended(bool isSuspended)
{
	m_isSuspended = isSuspended;
}

void IState::Terminate()
{
	if (m_terminateCallback)
	{
		m_terminateCallback();
	}
}

bool IState::GetIsSuspended() const
{
	return m_isSuspended;
}
