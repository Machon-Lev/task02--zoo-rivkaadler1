#pragma once
#include <iostream>

/**
 * @struct Location
 * @brief Represents a location with row and column coordinates.
 *
 * The Location struct represents a location in a two-dimensional space.
 * It contains row and column coordinates.
 */
struct Location {
    int _row;
    int _col;

    /**
     * @brief Constructs a Location object with the specified row and column coordinates.
     *
     * @param r The row coordinate.
     * @param c The column coordinate.
     */
    Location(int r = 0, int c = 0);

    // output operator
    friend std::ostream& operator<<(std::ostream& os, const Location& loc);

    // addition assignment operator
    Location& operator+=(const Location& rhs);

    // addition assignment operator
    Location& operator+=(const int num);

    // equality operator
    bool operator==(const Location& rhs) const;

    // inequality operator
    bool operator!=(const Location& rhs) const;
};



