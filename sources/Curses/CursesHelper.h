#pragma once

#include <curses.h>

/*!  A collection of helper functions and structs for use with curses.
|*|
|*|  Naming conventions for memo are intentionally broken here in favor
|*|  of those used by curses.
|*/
namespace curses
{
	/*!  Representation of a yx position.
	|*/
	struct yx
	{
		yx() : y(0), x(0) {};
		int y;
		int x;
	};

	/*!  Enumerates directions for cursor movement.
	|*/
	enum cursdir
	{
		up,
		down,
		left,
		right
	};

	/*!  Checks whether a given position is inside the given window.
	|*|
	|*|  @param  window  window against which to check position
	|*|  @param  y  the vertical coordinate of the position to check
	|*|  @param  x  the horizontal coordinate of the position to check
	|*|
	|*|  @return  true if the position is inside the window, false otherwise
	|*/
	inline bool yxinwindow(WINDOW* window, int y, int x)
	{
		return x >= 0 && x < window->_maxx && y >= 0 && y < window->_maxy;
	}
}