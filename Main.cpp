#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ZooAnimal.h"
#include "Zoo.h"

using namespace std;

int main()
{
	std::srand(std::time(nullptr));
	Zoo zoo;
	zoo.run();
	return 1;
}