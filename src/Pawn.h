/*
 * Pawn.h
 *
 *  Created on: Mar 19, 2015
 *      Author: Michael
 */

#ifndef PAWN_H_
#define PAWN_H_

// Includes
#include "RestrictedPiece.h"

// A Pawn's value is a attribute of the class Pawn.
static int PAWN_VALUE = 1;

/**
 * Class for representing a Pawn on a chess board.
 * Inherits from class ResctictedPiece.
 * A Pawn may move one Square at a time, except for its first move, at
 * which time it may move two Squares, providing that they are unoccupied.
 * The only case in which a Pawn may move diagonally is to capture a Piece.
 */
class Pawn: public RestrictedPiece
{
    public:
        // Constructor

        /**
         * Constructor for a Pawn Piece.
         * @param color the color of the Pawn, defaults to an empty space.
         */
        Pawn(string color);

        // Accessors

        /**
         * Returns the value of the Pawn.
         * @return The value of the Pawn.
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
         * Moves a Piece to the Square passed as an argument.
         * @param byPlayer The Player moving the Piece.
         * @param to The Square to move the Piece to.
         * @return True if the move was successful, False otherwise.
         */
        bool moveTo(Player& byPlayer, Square& to);

        /**
         * Displays the Pawn to the ostream passed as an argument.
         * @param outStream The ostream to display the Pawn to.
         */
        void display(ostream& outStream) const;

        /**
         * Sets the location of the Piece to the Square passed as an argument.
         * @param square The Square to set the location of the Piece to.
         */
        const void setLocation(Square* square);

        // Destructor

        /**
         * Destructor, used to remove any delegate garbage leftover.
         */
        ~Pawn();

    private:

        // Attributes of a Pawn
        // _delegate is a pointer to the Piece delegated to act for the Pawn.
        Piece* _delegate;
};

#endif /* PAWN_H_ */
