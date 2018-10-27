#pragma once

/*! Interface for application states, which draw the GUI and take
 *  input for different memo commands.
 */
class IState
{
public:
	/*! Begins execution of the state.
	 */
	virtual void Run() = 0;

	/*! Suspends the execution of the state.
	 */
	virtual void Suspend() = 0;
};

typedef std::shared_ptr<IState> IStatePtr;