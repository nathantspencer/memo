#include "UniversalNewState.h"

#include <States/ViewState/Win32ViewState.h>


void UniversalNewState::Execute()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	WINDOW* dateTimeWindow = newwin(LINES - 2, 11, 1, 2);
	m_textWindow = newwin(LINES - 2, COLS - 17, 1, 15);

	int key = KEY_RESIZE;
	do
	{
		if (key == KEY_RESIZE)
		{
			resize_term(0, 0);
			wresize(dateTimeWindow, LINES - 2, 11);
		}

		mvwprintw(dateTimeWindow, 0, 0, " 9/27/18");
		mvwprintw(dateTimeWindow, 1, 0, "10:03 PM");
		mvwvline(dateTimeWindow, 0, 10, ACS_VLINE, LINES - 2);

		if (key == KEY_UP)
		{
			MoveTextWindowCursor(curses::up);
		}
		else if (key == KEY_DOWN)
		{
			MoveTextWindowCursor(curses::down);
		}
		else if (key == KEY_LEFT)
		{
			MoveTextWindowCursor(curses::left);
		}
		else if (key == KEY_RIGHT)
		{
			MoveTextWindowCursor(curses::right);
		}
		else if (key == 8) // TODO: fix this hack for PC backspace
		{
			MoveTextWindowCursor(curses::left);
			waddch(dateTimeWindow, ' '); // TODO: is there a better empty character that can be used?
			MoveTextWindowCursor(curses::left);
			// TODO: backspace should shift all trailing characters to the left
		}
		else if (key != KEY_RESIZE && key != ERR)
		{
			waddch(dateTimeWindow, key);
		}

		move(getbegy(m_textWindow) + getcury(m_textWindow), getbegx(m_textWindow) + getcurx(m_textWindow));
		curs_set(0);
		wrefresh(dateTimeWindow);
		wrefresh(m_textWindow);
		curs_set(1);
		refresh();
	}
	while (key = getch());

	delwin(dateTimeWindow);
}

void UniversalNewState::MoveTextWindowCursor(curses::cursdir direction)
{
	int y = getcury(m_textWindow);
	int x = getcurx(m_textWindow);

	switch (direction)
	{
	case curses::up:
		wmove(m_textWindow, y - 1, x);
		break;
	case curses::down:
		if (ContainsCharacter(y + 1, x))
		{
			wmove(m_textWindow, y + 1, x);
		}
		break;
	case curses::left:
		if (curses::yxinwindow(m_textWindow, y, x - 1))
		{
			wmove(m_textWindow, y, x - 1);
		}
		else
		{
			wmove(m_textWindow, y - 1, m_textWindow->_maxx - 1);
		}
		break;
	case curses::right:
		if (curses::yxinwindow(m_textWindow, y, x + 1))
		{
			wmove(m_textWindow, y, x + 1);
		}
		else
		{
			wmove(m_textWindow, y + 1, 0);
		}
		break;
	default:
		break;
	}
}

bool UniversalNewState::ContainsCharacter(int y, int x) const
{
	return y >= 0 && y <= m_endYX.y && x >= 0 && x <= m_endYX.x;
}
