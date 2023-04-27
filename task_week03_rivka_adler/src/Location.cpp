#include <iostream>
struct Location {
    int row;
    int col;

    // output operator
    friend std::ostream& operator<<(std::ostream& os, const Location& loc) {
        os << "(" << loc.row << ", " << loc.col << ")";
        return os;
    }

    // addition assignment operator
    Location& operator+=(const Location& rhs) {
        row += rhs.row;
        col += rhs.col;
        return *this;
    }

    // equality operator
    bool operator==(const Location& rhs) const {
        return (row == rhs.row && col == rhs.col);
    }

    // inequality operator
    bool operator!=(const Location& rhs) const {
        return !(*this == rhs);
    }
};