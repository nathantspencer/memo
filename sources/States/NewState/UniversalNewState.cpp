#include "UniversalNewState.h"

#include <States/ViewState/Win32ViewState.h>

#include <curses.h>

enum CursorDirection { UP, DOWN, LEFT, RIGHT };

/// -- Moves the cursor by one character in the given direction/panel
/// -- Wraps over the ends of lines when moving left/right
static void MoveCursor(WINDOW* panel, CursorDirection direction)
{
	// TODO: fix up/down
	if (direction == UP || direction == DOWN)
	{
		wmove(panel, getcury(panel) + !!(direction == UP), getcurx(panel) + !!(direction == DOWN));
	}
	else if (direction == LEFT)
	{
		if (!getcurx(panel) && !!getcury(panel))
		{
			wmove(panel, getcury(panel) - 1, panel->_maxx - 1);
		}
		else
		{
			wmove(panel, getcury(panel), getcurx(panel) - 1);
		}
	}
	else if (direction == RIGHT)
	{
		if (getcurx(panel) == panel->_maxx - 1 && getcury(panel) != panel->_maxx)
		{
			wmove(panel, getcury(panel) + 1, 0);
		}
		else
		{
			wmove(panel, getcury(panel), getcurx(panel) + 1);
		}
	}
}

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

		if (key == KEY_UP)
		{
			MoveCursor(textPanel, UP);
		}
		else if (key == KEY_DOWN)
		{
			MoveCursor(textPanel, DOWN);
		}
		else if (key == KEY_LEFT)
		{
			MoveCursor(textPanel, LEFT);
		}
		else if (key == KEY_RIGHT)
		{
			MoveCursor(textPanel, RIGHT);
		}
		else if (key == 8) // TODO: fix this hack for PC backspace
		{
			MoveCursor(textPanel, LEFT);
			waddch(textPanel, ' '); // TODO: is there a better empty character that can be used?
			MoveCursor(textPanel, LEFT);
			// TODO: backspace should shift all trailing characters to the left
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