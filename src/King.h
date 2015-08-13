/*
 * King.h
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

#ifndef KING_H_
#define KING_H_

// Includes
#include "RestrictedPiece.h"

// A King's value is a attribute of the class King.
static int KING_VALUE = 0;

/**
 * Class for representing a King on a chess board.
 * Inherits from class RestrictedPiece.
 * A King may move one space at at time, in any direction, as long as no
 * one of the other Player's Pieces can move to the Square the King is on
 */
class King: public RestrictedPiece
{
    public:
        // Constructor

        /**
         * Constructor for a King Piece.
         * @param color the color of the King, defaults to an empty space.
         */
        King(string color);

        /**
         * Returns the value of the King.
         * @return The value of the King.
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
         * Displays the King to the ostream passed as an argument.
         * @param outStream The ostream to display the King to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used, the King may never die!
         */
        ~King();
};

#endif /* KING_H_ */
