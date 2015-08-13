/*
 * Bishop.h
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

#ifndef BISHOP_H_
#define BISHOP_H_

// Includes
#include "Piece.h"

// A Bishop's value is a attribute of the class Bishop.
static int BISHOP_VALUE = 3;

/**
 * Class for representing a Bishop on a chess board.
 * Inherits from class Piece.
 * A Bishop may move diagonally, on a straight path, until it
 * encounters another Piece.
 */
class Bishop: public Piece
{
    public:
        // Constructor

        /**
         * Constructor for a Bishop Piece.
         * @param color the color of the Bishop, defaults to an empty space.
         */
        Bishop(string color);

        // Accessors

        /**
         * Returns the value of the Bishop.
         * @return The value of the Bishop.
         */
        const int value() const;

        /**
         * Returns True if the Piece can move to the location passed as an
         * argument, returns False otherwise.
         * @param location The square to check.
         * @return True if the Piece can move to the location, False otherwise.
         */
        bool canMoveTo(Square& location) const;

        /**
         * Displays the Bishop to the ostream passed as an argument.
         * @param outStream The ostream to display the Bishop to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used.
         */
        ~Bishop();
};

#endif /* BISHOP_H_ */
