#pragma once

#include <States/ViewState/IViewState.h>

/*! Win32 implementation of the "view" state, used by
 *  memo in response to the command `memo view`. /file
 */
class Win32ViewState : public IViewState
{
	virtual void Execute();
};