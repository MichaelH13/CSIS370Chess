/*
 * King.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

// Includes
#include "King.h"
#include "Square.h"
#include "Board.h"

// Construct a new King RestrictedPiece.
King::King(string color) :
        RestrictedPiece(color)
{

}

// Check if the King can move to the location passed as an argument.
bool King::canMoveTo(Square& location) const
{
    // If we are moving at most one Square from our current position, then it is a legal move.
    bool canMoveTo = abs(((*this).location().getX() - location.getX())) < 2 && abs(((*this).location().getY() - location.getY())) < 2;

    // If the Square we are moving to is either a clear vertical or
    // horizontal and the Square we are moving to is also unoccupied
    // or occupied by an opponent, then return true, otherwise return false.
    bool isOpponentOrEmpty =
            !Board::getBoard().squareAt(location.getX(), location.getY()).occupied()
                    || Board::getBoard().squareAt(location.getX(),
                            location.getY()).occupiedBy().color() != color();

    // Return true if the Square we are moving to is empty or occupied by
    // an opponent and we are moving no more than 1 Square in any direction.
    return isOpponentOrEmpty && canMoveTo;
}

// Get the value of the King.
const int King::value() const
{
    // Return the King's value.
    return KING_VALUE;
}

// Display the King to the ostream passed as an argument.
void King::display(ostream& outStream) const
{
    // Display the King's color and the K representing the King.
    outStream << color() << 'K';
}

// Do nothing.
King::~King()
{

}
