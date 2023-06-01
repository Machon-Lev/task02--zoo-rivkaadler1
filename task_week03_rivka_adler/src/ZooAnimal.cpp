#include "ZooAnimal.h"

ZooAnimal::ZooAnimal(const std::string& name, const Location& loc)
    : _name(name), _location(loc), _stopped(false), _dir(1) {}

ZooAnimal::~ZooAnimal() {}

void ZooAnimal::printDetails() const {
    std::cout << "Name:" << _name << " Type:" << getInitial() << " Location:" << '(' << _location._row
        << "," << _location._col << ")" << std::endl;
}

const std::string& ZooAnimal::getName() const {
    return _name;
}

const Location& ZooAnimal::getLocation() const {
    return _location;
}

void ZooAnimal::stop() {
    _stopped = true;
}

bool ZooAnimal::isStopped() const {
    return _stopped;
}
