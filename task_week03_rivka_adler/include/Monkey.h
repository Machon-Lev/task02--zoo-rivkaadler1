#pragma once
#include "ZooAnimal.h"
#include<iostream>

/**
 * @class Monkey
 * @brief Represents a monkey in the zoo.
 *
 * The Monkey class is a derived class of ZooAnimal that represents a monkey in the zoo. Monkeys randomly jump a square or two in any direction
 * in straight lines. The size of the step and the direction of the jump are randomly determined every five turns, regardless of movement.
 */
class Monkey : public ZooAnimal
{
public:
    /**
     * @brief Constructs a Monkey object with the specified name and location.
     *
     * @param name The name of the monkey.
     * @param loc The location of the monkey.
     */
    Monkey(const std::string& name, const Location& loc);

    /**
     * @brief Gets the initial character representing the monkey type.
     *
     * @return The initial character 'M' representing a monkey.
     */
    char getInitial() const override;

    /**
     * @brief Performs a step for the monkey.
     *
     * This function is called every step to determine the monkey's behavior.
     * In the case of a monkey, it randomly jumps a square or two in any direction in straight lines.
     * The size of the step and the direction of the jump are randomly determined every five turns, regardless of movement.
     */
    void step() override;

    /**
     * @brief Moves the monkey according to its specific rules.
     *
     * This function changes the state of the monkey from stopped to moveable.
     */
    void move() override;

    /**
     * This function turns the monkey's direction vertically.
     */
    void turnVertically() override;

    /**
     * This function turns the monkey's direction horizontally.
     */
    void turnHorizontally() override;

private:
    int _turn_num; /**< The number of turns for the monkey. */
    int _step_size; /**< The size of the step for the monkey's jump. */
};

