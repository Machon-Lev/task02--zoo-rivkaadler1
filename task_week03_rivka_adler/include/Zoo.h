#pragma once
#include "ZooAnimal.h"
#include "Lion.h"
#include "Location.h"
#include "Monkey.h"
#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "ZooAnimal.h"
#include "Clownfish.h"

using namespace std;

/**
 * @class Zoo
 * @brief Represents a zoo that manages various animals.
 *
 * The Zoo class allows users to create, manage, and manipulate a collection of ZooAnimal objects.
 */
class Zoo
{
public:
    /**
     * @brief Default constructor for the Zoo class.
     */
    Zoo();
    /**
     * @brief destructor for the Zoo class.
    */
    ~Zoo();
    
    void printZooState();

    void printHelp();
    /**
     * @brief Runs the zoo management program.
     *
     * The run function starts the zoo management program and listens for user commands until the user chooses to exit.
     * It provides various commands to create, delete, move, and interact with the animals in the zoo.
     */
    void run();

    
    int getAnimalIndex();

    char getAnimalType();

private:
    bool _valid_command = true; /**< Flag indicating if the entered command is valid or not. */
    vector<ZooAnimal*> animals; /**< A collection of ZooAnimal objects representing the animals in the zoo. */

    string getAnimalName();

    /**
     * @brief Stops the specified animal from moving.
     *
     * The stop function receives the number of the animal in the list and stops it from moving.
     * The animal will remain stationary until the move command is applied to it again.
     *
     * @param num The number of the animal to stop.
     */
    void stop(int num);

    /**
     * @brief Moves the specified animal.
     *
     * The move function receives the number of the animal in the list and makes it move.
     * This command has meaning only if the animal was previously stopped.
     * When the animal begins to move, it recalibrates its direction according to predefined rules.
     *
     * @param num The number of the animal to move.
     */
    void move(int num);

    /**
     * @brief Creates a new animal and adds it to the zoo.
     *
     * The create function creates a new animal of the specified type and assigns a name to it.
     * The location of the animal is randomly determined.
     *
     * @param type The type of the animal to create.
     * @param name The name of the new animal.
     */
    void create(char type, string name);

    /**
     * @brief Deletes the specified animal from the zoo.
     *
     * The del function removes the animal with the given number from the list.
     *
     * @param num The number of the animal to delete.
     */
    void del(int num);

    /**
     * @brief Deletes all animals of a certain type from the zoo.
     *
     * The delAll function removes all animals of the specified type from the list, if they exist.
     *
     * @param type The type of the animals to delete.
     */
    void delAll(char type);

    /**
     * @brief Prints a map representing the zoo and the locations of the animals.
     *
     * The printMap function displays a visual representation of the zoo and the current locations of the animals.
     */
    void printMap();

    /**
     * @brief Prints a list of all the animals in the zoo.
     *
     * The printList function prints a list of all the animals in the zoo, along with their details.
     */
    void printList();

    /**
     * @brief Moves all the animals in the zoo according to predefined rules.
     *
     * The stepAll function moves all the animals in the zoo based on their current positions and predefined rules.
     */
    void stepAll();
};



