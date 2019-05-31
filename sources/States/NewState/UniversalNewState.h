#pragma once

#include <Curses/CursesHelper.h>
#include <States/NewState/INewState.h>

/*!  Universal implementation of the "new" state, used by
|*|  memo in response to the command `memo new`.
|*/
class UniversalNewState : public INewState
{
public:
	virtual void Execute();

private:
	/*!  Attempts to move the cursor within the text window.
	|*|  
	|*|  @param  direction  direction to attempt to move the cursor
	|*/
	void MoveTextWindowCursor(curses::cursdir direction);

	/*!  Tests whether an YX position in the text window contains a character.
	|*|  
	|*|  @param  y  the vertical coordinate of the position to check
	|*|  @param  x  the horizontal coordinate of the position to check
	|*|
	|*|  @return  true if the position contains a character, false otherwise
	|*/
	bool ContainsCharacter(int y, int x) const;

	WINDOW* m_textWindow;
	curses::yx m_endYX;
};