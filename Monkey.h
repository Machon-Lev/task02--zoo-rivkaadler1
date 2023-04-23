#pragma once
// Define the Monkey class
#include "ZooAnimal.h"
#include<iostream>
class Monkey : public ZooAnimal
{
public:
    Monkey(const std::string& name, const Location& loc)
        : ZooAnimal(name, loc) {}
    char getInitial() const override { return 'M'; }
    void step() override;
    void move()override;
    void turnVertically() override;
    void turnHorizontally() override;
private:
    int _turn_num = 0;
    int _step_size = 1;
    int _dir = 0;
};
