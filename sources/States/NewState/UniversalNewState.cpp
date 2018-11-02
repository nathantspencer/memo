#include "UniversalNewState.h"

#include <States/ViewState/Win32ViewState.h>

#include <curses.h>

void UniversalNewState::Execute()
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);

	WINDOW* dateTimePanel = newwin(LINES - 2, 11, 1, 2);
	WINDOW* textPanel = newwin(LINES - 2, COLS - 17, 1, 15);

	int key;
	while (key = getch())
	{
		if (key == KEY_RESIZE)
		{
			resize_term(0, 0);
			wresize(dateTimePanel, LINES - 2, 11);
		}

		mvwprintw(dateTimePanel, 0, 0, " 9/27/18");
		mvwprintw(dateTimePanel, 1, 0, "10:03 PM");
		mvwvline(dateTimePanel, 0, 10, ACS_VLINE, LINES - 2);

		if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		{
			std::pair<int, int> cursorOffset;
			cursorOffset.first = (key == KEY_UP ? -1 : 0) + (key == KEY_DOWN ? 1 : 0);
			cursorOffset.second = (key == KEY_LEFT ? -1 : 0) + (key == KEY_RIGHT ? 1 : 0);
			wmove(textPanel, getcury(textPanel) + cursorOffset.first, getcurx(textPanel) + cursorOffset.second);
		}
		else if (key != KEY_RESIZE && key != ERR)
		{
			waddch(textPanel, key);
		}

		wrefresh(dateTimePanel);
		curs_set(1);
		wrefresh(textPanel);
		curs_set(0);
		refresh();
	}

	delwin(dateTimePanel);
}
