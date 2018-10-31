#include <States/StateFactory.h>

#include <States/NewState/UniversalNewState.h>
#include <States/ViewState/Win32ViewState.h>

std::shared_ptr<INewState> StateFactory::CreateNewState()
{
	return std::make_shared<UniversalNewState>();
}

std::shared_ptr<IViewState> StateFactory::CreateViewState()
{
#ifdef WIN32
	return std::make_shared<Win32ViewState>();
#endif

	// TODO: reasonable default
	return std::shared_ptr<Win32ViewState>();
}
