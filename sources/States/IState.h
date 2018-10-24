#pragma once

/*! Interface for application states, which draw the GUI and take
 *  input for different memo commands.
 *
 *  States should be managed and run by an instance of `StateDriver`.
 */
class IState
{
public:
	virtual void Run() = 0;
};