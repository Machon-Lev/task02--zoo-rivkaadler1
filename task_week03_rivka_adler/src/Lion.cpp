#include "Lion.h"

/*A lion always moves two spaces and always to the right or left.He keeps the same direction until he
 reaches the edge of the board and then turns back and so on, or until it stops (after stop) and then with the 
 next move command it will randomly re-choose its direction*/
void Lion::step()
{
    if (!_stopped)
    {
        if (_dir == 1)
        {
            if (_location._col > 37)
            {
                _location._col = 39 - (2 - (39 - _location._col));
                turnHorizontally();
            }
            else
            {
                _location._col += 2;
            }
        }
        else
        {
            if (_location._col == 1)
            {
                _location._col = 1;
                turnHorizontally();
            }
            else if (_location._col == 0)
            {
                _location._col = 1;
                turnHorizontally();
            }
            else
            {
                _location._col -= 2;
            }
        }
    }
}

void Lion::move()
{
    {
        if (_stopped)
        {
            _dir = std::rand() % 2 == 0 ? 1 : -1;
            _stopped = false;
        }
    }
}