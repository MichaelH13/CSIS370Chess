/*
 * Knight.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: 1825794
 */

// Includes
#include "Knight.h"
#include "Square.h"
#include "Board.h"

// Construct a new Knight Piece.
Knight::Knight(string color) :
        Piece(color)
{

}

// Get the value of the Knight.
const int Knight::value() const
{
    // Return Knight's value.
    return KNIGHT_VALUE;
}

// Check if the Knight can move to the location passed as an argument.
bool Knight::canMoveTo(Square& location) const
{
    // See class declaration for explanation of Knight
    // move style for additional information.
    bool canMoveTo = (abs((*this).location().getX() - location.getX()) == 2
            && abs((*this).location().getY() - location.getY()) == 1)
            || (abs((*this).location().getY() - location.getY()) == 2
                    && abs((*this).location().getX() - location.getX()) == 1);

    // If the Square we are moving to is either a clear vertical or
    // horizontal and the Square we are moving to is also unoccupied
    // or occupied by an opponent, then return true, otherwise return false.
    bool isOpponentOrEmpty =
            !Board::getBoard().squareAt(location.getX(), location.getY()).occupied()
                    || Board::getBoard().squareAt(location.getX(),
                            location.getY()).occupiedBy().color() != color();

    // Return true if the Square we are moving to has an opponent or is empty.
    return isOpponentOrEmpty && canMoveTo;
}

// Display the Knight to the ostream passed as an argument.
void Knight::display(ostream& outStream) const
{
    // Display the Knight's color and the N representing the Knight.
    outStream << color() << "N";
}

// Do nothing.
Knight::~Knight()
{

}
