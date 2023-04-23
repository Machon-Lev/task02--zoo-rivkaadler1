#include "Clownfish.h"

void Clownfish::step()
{
    int diff = 0;
    if (!_stopped)
    {
        switch (_dir)
        {
        case 0://left
            diff = _location._col -1;
            if (diff < 0)
            {
                _location._col = 1;
                turnHorizontally();
            }
            else
            {
                _location._col -= 1;
            }
            break;
        case 1://right
            diff = _location._col + 1;
            if (diff > 39)
            {
                _location._col --;
                turnHorizontally();
            }
            else
            {
                _location._col ++;
            }

            break;
        case 2://down
            diff = _location._row -1;
            if (diff < 0)
            {
                _location._row++;
                turnVertically();
            }
            else
            {
                _location._row--;
            }
            break;
        case 3://up 
            diff = _location._row + 1;
            if (diff > 19)
            {
                _location._row--;
                turnVertically();
            }
            else
            {
                _location._row ++;
            }
        break;
        case 4://right up
            if (_location._row + 1 < 20)
            {
                _location._row ++;
            }
            else if(_location._row + 1 == 20 )
            {
                _location._row--;
                turnVertically();
            }
            if (_location._col + 1 < 40)
            {
                _location._col++;
            }
            else if (_location._col + 1 == 40)
            {
                _location._col--;
                turnHorizontally();
            }
            break;
        case 5://right down
            if (_location._row + 1 < 20)
            {
                _location._row++;
            }
            else if (_location._row + 1 == 20)
            {
                _location._row--;
                turnVertically();
            }
            if (_location._col - 1 > -1)
            {
                _location._col--;
            }
            else if (_location._col - 1 == -1)
            {
                _location._col++;
                turnHorizontally();
            }
            break;
        case 6://left up
            if (_location._row +1 < 20)
            {
                _location._row++;
            }
            else if (_location._row + 1 == 20)
            {
                _location._row--;
                turnVertically();
            }
            if (_location._col - 1 > -1)
            {
                _location._col--;
            }
            else if (_location._col - 1 == -1)
            {
                _location._col++;
                turnHorizontally();
            }
            break;
        case 7://left down
            if (_location._row - 1 >-1)
            {
                _location._row--;
            }
            else if (_location._row - 1 == -1)
            {
                _location._row++;
                turnVertically();
            }
            if (_location._col - 1 > -1)
            {
                _location._col--;
            }
            else if (_location._col - 1 == -1)
            {
                _location._col++;
                turnHorizontally();
            }
            break;


        }
    }
}

void Clownfish::move()
{
    if (_stopped)
    {
        _dir = rand() % 8;
        _stopped = false;
    }
}

void Clownfish::turnVertically()
{
    switch (_dir)
    {
    case 2:
        _dir = 3;
        break;
    case 3:
        _dir = 2;
        break;
    case 4:
        _dir = 5;
        break;
    case 5:
        _dir = 4;
        break;
    case 6:
        _dir = 7;
        break;
    case 7:
        _dir = 6;
        break;
    }
}

void Clownfish::turnHorizontally()
{
    switch (_dir)
    {
    case 0:
        _dir = 1;
        break;
    case 1:
        _dir = 0;
        break;
    case 4:
        _dir = 6;
        break;
    case 5:
        _dir = 7;
        break;
    case 6:
        _dir = 4;
        break;
    case 7:
        _dir = 5;
        break;
   

    }
}
