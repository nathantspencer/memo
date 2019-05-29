#include "UniversalNewState.h"

#include <States/ViewState/Win32ViewState.h>

#include <curses.h>

static enum CursorDirection { UP, DOWN, LEFT, RIGHT };


static bool IsYXInWindow(WINDOW* window, int y, int x)
{
	return x >= 0 && x < window->_maxx && y >= 0 && y < window->_maxy;
}

static void MoveCursor(WINDOW* window, CursorDirection direction)
{
	int y = getcury(window);
	int x = getcurx(window);

	switch (direction)
	{
	case UP:
		wmove(window, y - 1, x);
		break;
	case DOWN:
		wmove(window, y + 1, x);
		break;
	case LEFT:
		if (IsYXInWindow(window, y, x - 1))
		{
			wmove(window, y, x - 1);
		}
		else
		{
			wmove(window, y - 1, window->_maxx - 1);
		}
		break;
	case RIGHT:
		if (IsYXInWindow(window, y, x + 1))
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