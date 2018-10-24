#pragma once

#include <States/IState.h>

/*! Interface for platform-specific implementations of the "new" state,
 *  used by memo in response to the command `memo new`.
 */
class INewState : public IState
{
public:
	virtual void Run() = 0;
};