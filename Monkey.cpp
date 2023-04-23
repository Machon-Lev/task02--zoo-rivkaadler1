#include "Monkey.h"

void Monkey::step()
{
    int diff = 0;
    if (!_stopped)
    {
        _turn_num++;
        if (_turn_num%5 == 0) 
        {
            _step_size= rand() %2+1;
            _dir= rand() % 4;
        }
        switch (_dir)
        {
        case 0://left
            diff = _location._col - _step_size;
            if (diff <= 0)
            {
                if (diff == 0)
                {
                    _location._col = _step_size;
                }
                else if (diff == -1)
                {
                    _location._col = 1;
                }
                else if (diff == -2)
                {
                    _location._col = 0;
                }
                turnHorizontally();
            }
            else
            {
                _location._col -= _step_size;
            }
            break;
        case 1://right
            diff = _location._col + _step_size;
            if (diff > 39)
            {
                if (diff == 40)
                {
                    _location._col = 38;
                }
                else if (diff == 41)
                {
                    _location._col = 39;
                }
                turnHorizontally();
            }
            else
            {
                _location._col += _step_size;
            }

            break;
        case 2://down
            diff = _location._row - _step_size;
            if (diff < 0)
            {
                if (diff == -1)
                {
                    _location._row = 1;
                }
                if (diff == -2)
                {
                    _location._row = 2;
                }
                turnVertically();
            }
            else
            {
                _location._row = _location._row - _step_size;
            }
            break;
        case 3://up 
            diff = _location._row + _step_size;
            if (diff > 19)
            {
                if (diff == 20)
                {
                    _location._row = 18;
                }
                if (diff == 21)
                {
                    _location._row = 17;
                }
                turnVertically();
            }
            else
            {
                _location._row += _step_size;
            }
            break;
        }
    }
}

void Monkey::move()
{
    if (_stopped)
    {
        _stopped = false;
    }
}

void Monkey::turnVertically()
{
    switch (_dir)
    {
    case 2:
        _dir = 3;
        break;
    case 3:
        _dir = 2;
        break;
    }
}

void Monkey::turnHorizontally()
{
    switch (_dir)
    {
    case 0:
        _dir = 1;
        break;
    case 1:
        _dir = 0;
        break;
    }
}

