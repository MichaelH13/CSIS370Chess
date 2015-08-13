/*
 * Rook.h
 *
 *  Created on: Mar 19, 2015
 *      Author: 1825794
 */

#ifndef ROOK_H_
#define ROOK_H_

// Includes
#include "RestrictedPiece.h"

// A Rook's value is a attribute of the class Rook.
static int ROOK_VALUE = 5;

/**
 * Class for representing a Rook on a chess board.
 * Inherits from class RestrictedPiece.
 * A Rook may move diagonally, on a straight path, until it
 * encounters another Piece.
 */
class Rook: public RestrictedPiece
{
    public:
        // Constructor

        /**
         * Constructor for a Rook Piece.
         * @param color the color of the Rook, defaults to an empty space.
         */
        Rook(string color = "");

        // Accessors

        /**
         * Returns the value of the Rook.
         * @return The value of the Rook.
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
         * Displays the Rook to the ostream passed as an argument.
         * @param outStream The ostream to display the Rook to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used.
         */
        ~Rook();
};

#endif /* ROOK_H_ */
