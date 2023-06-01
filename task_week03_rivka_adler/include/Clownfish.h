#pragma once
#include "ZooAnimal.h"

/**
 * @class Clownfish
 * @brief Represents a clownfish in the zoo.
 *
 * The Clownfish class is a derived class of the ZooAnimal class.
 * It defines the behavior and characteristics specific to a clownfish.
 */
class Clownfish : public ZooAnimal {
public:
    /**
     * @brief Constructs a Clownfish object with the specified name and location.
     *
     * @param name The name of the clownfish.
     * @param loc The location of the clownfish.
     */
    Clownfish(const std::string& name, const Location& loc);

    /**
     * @brief Gets the initial character of the clownfish's name.
     *
     * @return The first letter of the clownfish's name, to be used for printing on the map.
     */
    char getInitial() const override;

    /**
     * @brief Performs a step for the clownfish.
     *
     * This function defines the behavior of the clownfish during a step.
     * The clownfish moves one square at a time and changes its direction randomly among all possible directions.
     * If the clownfish reaches the edge of the board, it turns back and continues in the opposite direction.
     */
    void step() override;

    /**
     * @brief Moves the clownfish according to its specific rules.
     *
     * In the case of a clownfish, it randomly selects a direction (left, right, up, down, right-up, right-down, left-up, or left-down) when it is stopped.
     * and makes the state of the Clownfish to be moveable.
     */
    void move() override;

    /**
     * @brief Turns the clownfish's direction vertically.
     *
     * Causes the clownfish to change its vertical direction without changing its speed.
     */
    void turnVertically() override;

    /**
     * @brief Turns the clownfish's direction horizontally.
     *
     * Causes the clownfish to change its horizontal direction without changing its speed.
     */
    void turnHorizontally() override;
};

