#pragma once

#include <States/IState.h>

/*! Interface for platform-specific implementations of the "view" state,
 *  used by memo in response to the command `memo view`.
 */
class IViewState : public IState
{
	virtual ~IViewState() {};
};