#pragma once
#include <States/IState.h>

#include <vector>

/*! Maintains and executes a stack of states.
 *  
 *  The top state on the stack is the currently executing state, and
 *  all states below it are suspended.
 *
 *  TODO: observer that will watch for the state to close
 */
class StateDriver
{
public:
	/*! Suspends the current state if one exists, and adds the given
	 *  kostate to the top of the stack.
	 */
	void PushState(IStatePtr state);

private:
	std::vector<IStatePtr> m_stateStack;
};