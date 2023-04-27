#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Location.h"


// Define the Animal base class
class ZooAnimal {
public:
    ZooAnimal(const std::string& name, const Location& loc)
        : _name(name), _location(loc), _stopped(false) {}

    virtual ~ZooAnimal() {}

    void printDetails() const {
        std::cout << "Name:" << _name << " Type:" << getInitial() << " Location:" << '(' << _location._row
            << "," << _location._col << ")" << std::endl;
    };

    const std::string& getName() const { return _name; }

    virtual char getInitial() const = 0;

    const Location& getLocation() const { return _location; }

    void stop() { _stopped = true; }

    virtual void move() = 0;


    bool isStopped() const { return _stopped; }
    virtual void turnVertically() = 0;
    virtual void turnHorizontally() = 0;

    virtual void step() = 0;

protected:
    std::string _name;
    Location _location;
    bool _stopped;
    int _dir = 1;
};
