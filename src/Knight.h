/*
 * Knight.h
 *
 *  Created on: Mar 18, 2015
 *      Author: 1825794
 */

#ifndef KNIGHT_H_
#define KNIGHT_H_

// Includes
#include "Piece.h"

// A Knight's value is a attribute of the class Knight.
static int KNIGHT_VALUE = 3;

/**
 * Class for representing a Knight on a chess board.
 * Inherits from class Piece.
 * A Knight may move in an L-shape, hopping over Pieces if they are
 * in its way (i.e. 2 Squares up, 1 Square down, or vice versa).
 */
class Knight: public Piece
{
    public:
        // Constructor

        /**
         * Constructor for a Knight Piece.
         * @param color the color of the Knight, defaults to an empty space.
         */
        Knight(string color);

        // Accessors

        /**
         * Returns the value of the Knight.
         * @return The value of the Knight.
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
         * Displays the Knight to the ostream passed as an argument.
         * @param outStream The ostream to display the Knight to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used.
         */
        ~Knight();
};

#endif /* KNIGHT_H_ */
