#include "Win32NewState.h"

#include <States/ViewState/Win32ViewState.h>

#include <curses.h>

void Win32NewState::Run()
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	WINDOW* dateTimePanel = newwin(LINES - 2, 11, 1, 2);

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
}
