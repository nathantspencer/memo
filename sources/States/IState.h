#pragma once
#include <functional>
#include <memory>

/*! Interface for application states, which draw the GUI and take
 *  input for different memo commands.
 *
 *  @see  StateDriver
 */
class IState
{
public:
	/*! Default constructor for `IState`.
	 */
	IState();

	/*! Constructor for `IState` which includes a callback for the
	 *  state's termination.
	 *
	 *  @param  terminateCallback  function to be called when state terminates
	 */
	IState(std::function<void()> terminateCallback);

	/*! Begins the execution of the state.
	 */
	virtual void Execute() = 0;

	/*! Setter for suspending and resuming execution of the state.
	*
	*   @param  isSuspended  `true` to suspend the state, `false` to resume
	*/
	void SetIsSuspended(bool isSuspended);

protected:
	/*! Calls the termination callback function if one is set. Should
	 *  be called by all implementers when the state's execution is done.
	 */
	virtual void Terminate();

	/*! Getter for whether the state is suspended.
	*
	*   @return  `true` if state is suspended, otherwise `false`
	*/
	bool GetIsSuspended() const;

private:
	std::function<void()> m_terminateCallback;
	bool m_isSuspended;
};

typedef std::shared_ptr<IState> IStatePtr;