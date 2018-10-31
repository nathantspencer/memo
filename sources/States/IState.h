#pragma once
#include <functional>
#include <memory>

typedef std::shared_ptr<IState> IStatePtr;

/*! Interface for application states, which draw the GUI and take
 *  input for different memo commands.
 *
 *  @see  StateDriver
 */
class IState
{
public:
	/*! Adds a callback for the state's termination. Useful for classes that manage states.
	 *
	 *  @param  terminateHandler  callback for the state's termination
	 */
	void SetTerminateHandler(std::function<void()> terminateHandler);

	/*! Adds a callback used when the state attempts to temporarily delegate execution to
	 *  a child state. Useful for classes that manage states.
	 *
	 *  @param  addChildStateHandler  callback for the creation of child states
	 */
	void SetAddChildStateHandler(std::function<void(IStatePtr)> addChildStateHandler);

	/*! Begins the execution of the state.
	 */
	virtual void Execute() = 0;

protected:
	/*! Finishes things up and calls the state's termination handler if one exists.
	 *  Should be called by all implementers when the state's execution is done.
	 */
	virtual void Terminate();

	/*! Calls the add child state handler if one exists, attempting to temporarily
	 *  pass off execution to another 'child' state.
	 *
	 *  @param  childState  state to become a child of the calling state
	 */
	virtual void AddChildState(IStatePtr childState);

private:
	std::function<void()> m_terminateHandler;
	std::function<void(IStatePtr)> m_addChildStateHandler;
};