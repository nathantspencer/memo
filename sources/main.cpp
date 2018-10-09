#include <algorithm>
#include <iostream>

#include <curses.h>
#include <string>

#ifdef WIN32
#include <Windows.h>
#endif

constexpr char* VERSION = "0.1.0";

int main(int argc, char* argv[])
{
	// vv TO BECOME UNIVERSALNEWSTATE

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	WINDOW* dateTimePanel = newwin(LINES - 2, 11, 1, 2);

	// TODO: use wvline instead of a dividerPanel

	int key;
	while (key = getch())
	{
		curs_set(0);

		if (key == KEY_RESIZE)
		{
			resize_term(0, 0);
			wresize(dateTimePanel, LINES - 2, 11);
		}

		mvwprintw(dateTimePanel, 0, 0, " 9/27/18");
		mvwprintw(dateTimePanel, 1, 0, "10:03 PM");
		mvwvline(dateTimePanel, 0, 10, ACS_VLINE, LINES - 2);

		wrefresh(dateTimePanel);
		refresh();
		curs_set(1);
	}

	delwin(dateTimePanel);

	// ^^ TO BECOME UNIVERSALNEWSTATE

	if (argc > 1)
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		auto consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		std::string argument = argv[1];
		std::transform(argument.begin(), argument.end(), argument.begin(), tolower);

		if (argument == "new")
		{
			initscr();
			raw();
			keypad(stdscr, TRUE);
			noecho();

#ifdef WIN32
			halfdelay(5);
#endif

			

			do
			{
				refresh();
#ifdef WIN32
				int columns, rows;

				bool x = consoleHandle == INVALID_HANDLE_VALUE;
				GetConsoleScreenBufferInfo(consoleHandle, &consoleInfo);

				columns = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
				rows = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
#endif
				
			} while (getch());

			endwin();

			return 0;
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