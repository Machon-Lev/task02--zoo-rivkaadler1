#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Location.h"

/**
 * @class ZooAnimal
 * @brief Represents an animal in the zoo.
 *
 * The ZooAnimal class is an abstract base class that provides common functionality and attributes for different types of animals in the zoo.
 * It includes functions to get information about the animal, control its movement, and perform specific actions.
 */
class ZooAnimal {
public:
    /**
     * @brief Constructs a ZooAnimal object with the specified name and location.
     *
     * @param name The name of the animal.
     * @param loc The location of the animal.
     */
    ZooAnimal(const std::string& name, const Location& loc);

    /**
     * @brief Virtual destructor for the ZooAnimal class.
     */
    virtual ~ZooAnimal();

    /**
     * @brief Prints the details of the animal, including its name, type, and location.
     */
    void printDetails() const;

    /**
    * @brief Gets the name of the animal.
    *
    * @return The name of the animal.
    */
    const std::string& getName() const;


    /**
     * @brief Gets the initial character of the animal's name.
     *
     * @return The first letter of the animal's name, to be used for printing on the map.
     */
    virtual char getInitial() const = 0;

    /**
     * @brief Gets the location of the animal.
     *
     * @return The location of the animal.
     */
    const Location& getLocation() const;

    /**
     * @brief Stops the animal, preventing it from moving.
     */
    void stop();

    /**
     * @brief Moves the animal according to its specific rules.
     *
     * This function should be implemented in the derived classes to define the change to moveable behavior of each animal type.
     */
    virtual void move() = 0;

    /**
     * @brief Checks if the animal is currently stopped.
     *
     * @return True if the animal is stopped, false otherwise.
     */
    bool isStopped() const;

    /**
     * @brief Turns the animal's direction vertically.
     *
     * Causes the animal to change its vertical direction without changing its speed.
     */
    virtual void turnVertically() = 0;

    /**
     * @brief Turns the animal's direction horizontally.
     *
     * Causes the animal to change its horizontal direction without changing its speed.
     */
    virtual void turnHorizontally() = 0;

    /**
     * @brief Performs a step for the animal.
     *
     * This function should be implemented in the derived classes to define the behavior of each animal during a step.
     */
    virtual void step() = 0;

protected:
    std::string _name; /**< The name of the animal. */
    Location _location; /**< The location of the animal. */
    bool _stopped; /**< Flag indicating if the animal is currently stopped. */
    int _dir; /**< The direction of the animal's movement. */
};

