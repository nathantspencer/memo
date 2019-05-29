#include "UniversalNewState.h"

#include <States/ViewState/Win32ViewState.h>


static void MoveCursor(WINDOW* window, curses::cursdir direction)
{
	int y = getcury(window);
	int x = getcurx(window);

	switch (direction)
	{
	case curses::up:
		wmove(window, y - 1, x);
		break;
	case curses::down:
		wmove(window, y + 1, x);
		break;
	case curses::left:
		if (curses::yxinwindow(window, y, x - 1))
		{
			wmove(window, y, x - 1);
		}
		else
		{
			wmove(window, y - 1, window->_maxx - 1);
		}
		break;
	case curses::right:
		if (curses::yxinwindow(window, y, x + 1))
		{
			wmove(window, y, x + 1);
		}
		else
		{
			wmove(window, y + 1, 0);
		}
		break;
	default:
		break;
	}
}

void UniversalNewState::Execute()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	WINDOW* dateTimePanel = newwin(LINES - 2, 11, 1, 2);
	WINDOW* textPanel = newwin(LINES - 2, COLS - 17, 1, 15);

	int key = KEY_RESIZE;
	do
	{
		if (key == KEY_RESIZE)
		{
			resize_term(0, 0);
			wresize(dateTimePanel, LINES - 2, 11);
		}

		mvwprintw(dateTimePanel, 0, 0, " 9/27/18");
		mvwprintw(dateTimePanel, 1, 0, "10:03 PM");
		mvwvline(dateTimePanel, 0, 10, ACS_VLINE, LINES - 2);

		if (key == KEY_UP)
		{
			MoveCursor(textPanel, curses::up);
		}
		else if (key == KEY_DOWN)
		{
			MoveCursor(textPanel, curses::down);
		}
		else if (key == KEY_LEFT)
		{
			MoveCursor(textPanel, curses::left);
		}
		else if (key == KEY_RIGHT)
		{
			MoveCursor(textPanel, curses::right);
		}
		else if (key == 8) // TODO: fix this hack for PC backspace
		{
			MoveCursor(textPanel, curses::left);
			waddch(textPanel, ' '); // TODO: is there a better empty character that can be used?
			MoveCursor(textPanel, curses::left);
			// TODO: backspace should shift all trailing characters to the left
		}
		else if (key != KEY_RESIZE && key != ERR)
		{
			waddch(textPanel, key);
		}

		move(getbegy(textPanel) + getcury(textPanel), getbegx(textPanel) + getcurx(textPanel));
		curs_set(0);
		wrefresh(dateTimePanel);
		wrefresh(textPanel);
		curs_set(1);
		refresh();
	}
	while (key = getch());

	delwin(dateTimePanel);
}