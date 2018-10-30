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
	/*! Constructor for `IState`. Requires two functions as arguments: one that handles
	 *  the constructed state's termination and another that handles it's creation of
	 *  child states.
	 *
	 *  @param  terminateHandler  callback for the state's termination
	 *  @param  addChildStateHandler  callback for the creation of child states
	 */
	IState(std::function<void()> terminateHandler, std::function<void(IStatePtr)> addChildStateHandler);

	/*! Begins the execution of the state.
	 */
	virtual void Execute() = 0;

protected:
	/*! Finishes things up and calls the state's termination handler. Should be called
	 *  by all implementers when the state's execution is done.
	 */
	virtual void Terminate();

	/*! Calls the add child state handler, which should pass off execution to a child
	 *  state temporarily.
	 *
	 *  @param  childState  a new state which will become a child of the calling state
	 */
	virtual void AddChildState(IStatePtr childState);

private:
	std::function<void()> m_terminateHandler;
	std::function<void(IStatePtr)> m_addChildStateHandler;
};