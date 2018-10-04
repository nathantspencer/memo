#include <States/StateFactory.h>

#include <States/NewState/Win32NewState.h>
#include <States/ViewState/Win32ViewState.h>

std::shared_ptr<INewState> StateFactory::CreateNewState()
{
#ifdef WIN32
	return std::make_shared<Win32NewState>();
#endif

	// TODO: reasonable default
	return std::shared_ptr<INewState>();
}

std::shared_ptr<IViewState> StateFactory::CreateViewState()
{
#ifdef WIN32
	return std::make_shared<Win32ViewState>();
#endif

	// TODO: reasonable default
	return std::shared_ptr<IViewState>();
}
