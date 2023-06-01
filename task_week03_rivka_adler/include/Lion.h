#pragma once
#include "ZooAnimal.h"

/**
 * @class Lion
 * @brief Represents a lion in the zoo.
 *
 * The Lion class is a derived class of ZooAnimal that represents a lion in the zoo. Lions always move two spaces and always
 * to the right or left. They keep the same direction until they reach the edge of the board, then they turn back and continue in the opposite direction.
 * If a lion stops, it will choose its direction randomly on the next move command.
 */
class Lion : public ZooAnimal {
public:
    /**
     * @brief Constructs a Lion object with the specified name and location.
     *
     * @param name The name of the lion.
     * @param loc The location of the lion.
     */
    Lion(const std::string& name, const Location& loc);

    /**
     * @brief Gets the initial character representing the lion type.
     *
     * @return The initial character 'L' representing a lion.
     */
    char getInitial() const override;

    /**
     * @brief Performs a step for the lion.
     * 
     * In the case of a lion, it always moves two spaces and always to the right or left.
     * If the lion reaches the edge of the board, it turns back and continues in the opposite direction.
     */
    void step() override;

    /**
     * @brief Moves the lion according to its specific rules.
     *
     * If a lion stops, it will choose its direction randomly and change its state frome stopped to moveable.
     */
    void move() override;

    /**
     * @brief Turns the lion's direction vertically.
     *
     * This function is not applicable to a lion since its movement is only in horizontal directions (right or left).
     */
    void turnVertically() override;

    /**
     * @brief Turns the lion's direction horizontally.
     *
     * This function is used to change the lion's direction when it reaches the edge of the board.
     * If the lion is moving to the right, it will turn left, and vice versa.
     */
    void turnHorizontally() override;
};

