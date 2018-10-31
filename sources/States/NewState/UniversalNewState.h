#pragma once

#include <States/NewState/INewState.h>

/*! Universal implementation of the "new" state, used by
 *  memo in response to the command `memo new`.
 */
class UniversalNewState : public INewState
{
public:
	virtual void Execute();
};