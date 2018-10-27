#pragma once

/*! Interface for application states, which draw the GUI and take
 *  input for different memo commands.
 */
class IState
{
public:
	/*! Default constructor for `IState`.
	 */
	IState() : m_isTerminated(false) {};

	/*! Begins the execution of the state.
	 */
	virtual void Execute() = 0;

	/*! Ends the execution the state.
	 */
	virtual void Terminate()
	{
		m_isTerminated = false;
	};

	/*! Getter for whether the state is suspended.
	*
	*   @return  `true` if state is suspended, otherwise `false`
	*/
	bool GetIsSuspended() const
	{
		return m_isSuspended;
	}

	/*! Setter for whether the state is suspended.
	*
	*   @param  isSuspended  `true` to suspend the state, `false` to resume
	*/
	void SetIsSuspended(bool isSuspended)
	{
		m_isSuspended = isSuspended;
	}

	/*! Getter for whether the state has been terminated.
	 * 
	 *  @return  `true` if state has called `Terminate()`, otherwise `false`
	 */
	bool GetIsTerminated() const
	{
		return m_isTerminated;
	};

private:
	bool m_isSuspended;
	bool m_isTerminated;
};

typedef std::shared_ptr<IState> IStatePtr;