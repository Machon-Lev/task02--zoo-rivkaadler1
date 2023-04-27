#pragma once
#include <iostream>
struct Location {
    int _row;
    int _col;
    Location(int r = 0, int c = 0) : _row(r), _col(c) {}

    // output operator
    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << "(" << loc._row << ", " << loc._col << ")";
        return os;
    }

    // addition assignment operator
    Location& operator+=(const Location& rhs) {
        _row += rhs._row;
        _col += rhs._col;
        return *this;
    }

    // addition assignment operator
    Location& operator+=(const int num) {
        _row += num;
        _col += num;
        return *this;
    }

    // equality operator
    bool operator==(const Location& rhs) const {
        return (_row == rhs._row && _col == rhs._col);
    }

    // inequality operator
    bool operator!=(const Location& rhs) const {
        return !(*this == rhs);
    }
};
