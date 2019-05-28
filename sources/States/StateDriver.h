#pragma once
#include <States/IState.h>

#include <vector>

/*!  Maintains and executes a stack of states.
|*|  
|*|  The top state on the stack is the currently executing state, and
|*|  all states below it are suspended.
|*|
|*|  @see  IState
|*/
class StateDriver
{
public:
	/*!  Adds the given state to the top of the stack and executes it.
	|*|	 
	|*|  @param  state  state to add to top of stack and execute
	|*/
	void PushState(IStatePtr state);

private:
	std::vector<IStatePtr> m_stateStack;
};