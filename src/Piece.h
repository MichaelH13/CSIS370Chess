/*
 * Piece.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Michael
 */

#ifndef PIECE_H_
#define PIECE_H_

// Includes
#include <ostream>

// Use the standard template library.
using namespace std;

// Forward declarations of classes that will be used.
class Square;
class Player;

/**
 * Class for representing a Piece on a chess board.
 * A Piece can move, tell us its value, display itself, have a Square location
 * assigned to it, tell us if it is on a Square, and return its location.
 */
class Piece
{
    public:
        // Constructor

        /**
         * Constructor for a chess Piece.
         * @param color the color of the Piece, defaults to an empty space.
         */
        Piece(string color);

        // Virtual methods

        /**
         * Returns the value of the Piece.
         * @return The value of the Piece.
         */
        virtual const int value() const = 0;

        /**
         * Returns True if the Piece can move to the location passed as an
         * argument, returns False otherwise.
         * @param location The square to check.
         * @return True if the Piece can move to the location, False otherwise.
         */
        virtual bool canMoveTo(Square& location) const = 0;

        /**
         * Displays the Piece to the ostream passed as an argument.
         * @param outStream The ostream to display the Piece to.
         */
        virtual void display(ostream& outStream) const = 0;

        // Non-virtual methods.

        /**
         * Moves a Piece to the Square passed as an argument.
         * @param byPlayer The Player moving the Piece.
         * @return True if the move was successful, False otherwise.
         */
        virtual bool moveTo(Player& byPlayer, Square& to);

        /**
         * Returns the color of the Piece.
         * @return The color of the Piece.
         */
        const string color() const;

        /**
         * Sets the location of the Piece to the Square passed as an argument.
         * @param square The Square to set the location of the Piece to.
         */
        virtual const void setLocation(Square* square);

        /**
         * Returns True if the Piece is on a Square, otherwise False.
         * @return True if the Piece is on a Square, otherwise False.
         */
        bool isOnSquare() const;

        /**
         * Returns the location of the Square.
         * @return The location of the Square.
         */
        Square& location() const;

        // Destructor

        /**
         * Destructor, not used.
         */
        virtual ~Piece();

    private:

        // Private attributes of a Piece.
        // _location is a pointer to the location of the Piece on the Board.
        // _color is the color of the Piece.
        Square* _location;
        string _color;
};

#endif /* PIECE_H_ */
