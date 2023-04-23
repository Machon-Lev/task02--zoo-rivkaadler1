// Define the Lion class
#include "Lion.h"
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
            if (_location._col==1)
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
            _dir = std::rand() % 2 == 0 ? 1 : -1;
            _stopped = false;
        }
    }
}
