#include <States/StateDriver.h>
#include <States/StateFactory.h>

#include <curses.h>

#include <algorithm>
#include <iostream>
#include <string>

constexpr char* VERSION = "0.1.0";

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::string argument = argv[1];
		std::transform(argument.begin(), argument.end(), argument.begin(), tolower);

		StateDriver stateDriver;
		if (argument == "new")
		{
			stateDriver.PushState(StateFactory::CreateNewState());
		}
		else if (argument == "view")
		{
			// TODO
		}
	}
	else
	{
		std::cout << "\n\t" << "memo v" << VERSION << "\n";
		std::cout << "\n\t" << "usage:" << "\n";
		std::cout << "\n\t" << "memo         display version and help";
		std::cout << "\n\t" << "memo new     begin a new memo";
		std::cout << "\n\t" << "memo view    browse saved memos" << "\n";
	}
	return 0;
}