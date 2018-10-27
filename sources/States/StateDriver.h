#pragma once
#include <States/IState.h>

#include <vector>

/*! Maintains and executes a stack of states.
 *  
 *  The top state on the stack is the currently executing state, and
 *  all states below it are suspended.
 *
 *  TODO: need some callback for terminate to pop the terminated state from the stack
 */
class StateDriver
{
public:
	/*! Suspends the current state if one exists, adds the given state
	 *  to the top of the stack, and executes it.
	 */
	void PushState(IStatePtr state);

private:
	std::vector<IStatePtr> m_stateStack;
};