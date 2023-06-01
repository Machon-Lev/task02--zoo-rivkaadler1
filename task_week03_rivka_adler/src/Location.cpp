#include "Location.h"

Location::Location(int r, int c) : _row(r), _col(c) {}

std::ostream& operator<<(std::ostream& os, const Location& loc) {
    os << "(" << loc._row << ", " << loc._col << ")";
    return os;
}

Location& Location::operator+=(const Location& rhs) {
    _row += rhs._row;
    _col += rhs._col;
    return *this;
}

Location& Location::operator+=(const int num) {
    _row += num;
    _col += num;
    return *this;
}

bool Location::operator==(const Location& rhs) const {
    return (_row == rhs._row && _col == rhs._col);
}

bool Location::operator!=(const Location& rhs) const {
    return !(*this == rhs);
}
