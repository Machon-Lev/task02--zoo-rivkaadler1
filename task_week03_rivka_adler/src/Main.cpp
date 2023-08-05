#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ZooAnimal.h"
#include "Zoo.h"

using namespace std;

/**
 * @brief The main entry point of the program.
 *
 * This function is the starting point of the program execution.
 * It initializes the random number generator, creates an instance of the Zoo class, and runs the zoo simulation.
 *
 * @return An integer representing the exit status of the program.
 */
int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Zoo zoo;
	zoo.run();
	return 1;
}