#pragma once
#include "ZooAnimal.h"
#include<iostream>
class Clownfish : public ZooAnimal
{
public:
    Clownfish(const std::string& name, const Location& loc)
        : ZooAnimal(name, loc) {}
    char getInitial() const override { return 'C'; }
    void step() override;
    void move()override;
    void turnVertically() override;
    void turnHorizontally() override;
};

