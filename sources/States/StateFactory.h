#pragma

#include <States/NewState/INewState.h>
#include <States/ViewState/IViewState.h>

#include <memory>

/*! A namespace for generating platform-appropriate instances of
 *  state classes.
 */
namespace StateFactory
{
	/*! Creates and returns a shared pointer to an implementation of
	 *  `INewState` appropriate for the current platform.
	 *
	 *  @return  a shared pointer to the created 'new' state
	 */
	std::shared_ptr<INewState> CreateNewState();

	/*! Creates and returns a shared pointer to an implementation of
	 *  `IViewState` appropriate for the current platform.
	 *
	 *  @return  a shared pointer to the created 'view' state
	 */
	std::shared_ptr<IViewState> CreateViewState();
};