#pragma

#include <States/NewState/INewState.h>
#include <States/ViewState/IViewState.h>

#include <memory>

/*! A namespace for generating platform-appropriate instances of
 *  state classes.
 */
namespace StateFactory
{
	// TODO: Doxygen comment
	std::shared_ptr<INewState> CreateNewState();

	// TODO: Doxygen comment
	std::shared_ptr<IViewState> CreateViewState();
};