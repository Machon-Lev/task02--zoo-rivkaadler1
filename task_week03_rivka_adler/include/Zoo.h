#pragma once
#include "ZooAnimal.h"
#include"Lion.h"
#include "Location.h"
#include "Monkey.h"
#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ZooAnimal.h"
#include "Clownfish.h"

using namespace std;
class Zoo
{
public:
    Zoo();
    void run();
private:
    bool _valid_command = true;
    vector<ZooAnimal*> animals;
    void stop(int num);
    void move(int num);
    void create(char type, string name);
    void del(int num);
    void delAll(char type);
    void printMap();
    void printList();
    void stepAll();
};
