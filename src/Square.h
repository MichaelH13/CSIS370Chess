/*
 * Square.h
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

#ifndef SQUARE_H_
#define SQUARE_H_

// Includes
#include "Piece.h"

#include <iostream>

/**
 * Class for representing a Square on a chess board.
 * A Square can tell its X and Y coordinate on the Board, whether or not it
 * is occupied, what it is occupied by, set its occupant, and display itself.
 */
class Square
{
    public:
        // Constructor

        /**
         * Constructor for a Square. Accepts an int x for the x position on
         * the Board, and an int y for they y position on the Board.
         * @param x The X coordinate the Square is located at on the Board.
         * @param y The Y coordinate the Square is located at on the Board.
         */
        Square(int x, int y);

        /**
         * Returns the X coordinate of the Square.
         * @return The X coordinate of the Square.
         */
        int getX() const;

        /**
         * Returns the Y coordinate of the Square.
         * @return The Y coordinate of the Square.
         */
        int getY() const;

        /**
         * Returns True if this Square is occupied, False otherwise.
         * @return True if this Square is occupied, False otherwise.
         */
        bool occupied() const;

        /**
         * Returns a reference to the Piece occupying this Square.
         * @return A reference to the Piece occupying this Square.
         */
        Piece& occupiedBy() const;

        /**
         * Set the occupier of this Square to be the Piece passed as an
         * argument.
         * @param piece The Piece to set to be this Square's occupant.
         */
        void setOccupier(Piece* piece);

        /**
         * Display the contents of this Square to the ostream passed as an
         * argument.
         * @param outStream The ostream to output the Square to.
         */
        void display(ostream& outStream) const;

        // Destructor

        /**
         * Destructor, not used.
         */
        ~Square();

    private:

        // Private attributes of a Square.
        // _piece is a pointer to the Piece occupying this Square.
        // _x is the X coordinate of the Square on the Board.
        // _y is the Y coordinate of the Square on the Board.
        Piece* _piece;
        int _x;
        int _y;
};

#endif /* SQUARE_H_ */
