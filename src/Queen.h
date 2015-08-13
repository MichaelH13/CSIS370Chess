/*
 * Queen.h
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

#ifndef QUEEN_H_
#define QUEEN_H_

// Includes
#include "Piece.h"

// A Queen's value is a attribute of the class Queen.
static int QUEEN_VALUE = 9;

/**
 * Class for representing a Queen on a chess board.
 * Inherits from class Piece.
 * A Queen may move diagonally or horizontally, on a straight path, until it
 * encounters another Piece.
 */
class Queen: public Piece
{
    public:
        // Constructor

        /**
         * Constructor for a Queen Piece.
         * @param color the color of the Queen, defaults to an empty space.
         */
        Queen(string color);

        // Accessors

        /**
         * Returns the value of the Queen.
         * @return The value of the Queen.
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
         * Displays the Queen to the ostream passed as an argument.
         * @param outStream The ostream to display the Queen to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used.
         */
        ~Queen();
};

#endif /* QUEEN_H_ */
