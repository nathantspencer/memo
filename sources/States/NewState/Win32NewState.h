#pragma once

#include <States/NewState/INewState.h>

/*! Win32 implementation of the "new" state, used by
 *  memo in response to the command `memo new`.
 */
class Win32NewState : public INewState
{
public:
	virtual void Run();
};