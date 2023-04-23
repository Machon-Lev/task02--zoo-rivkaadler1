#pragma once
// Define the Lion class
#include "ZooAnimal.h"
class Lion : public ZooAnimal {
public:
    Lion(const std::string& name, const Location& loc)
        : ZooAnimal(name, loc){}
    char getInitial() const override { return 'L'; }
    void step() override;
    void move()override;
    void turnVertically() override{  }
    void turnHorizontally() override{ _dir *= -1; }
};
