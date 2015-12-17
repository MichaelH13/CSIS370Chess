/*
 * Rook.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: 1825794
 */

// Includes
#include "Rook.h"
#include "Board.h"

// Construct a new Rook RestrictedPiece.
Rook::Rook(string color) :
        RestrictedPiece(color)
{

}

// Check if the Rook can move to the location passed as an argument.
bool Rook::canMoveTo(Square& location) const
{
    // If the Square we are moving to is either a clear vertical or
    // horizontal and the Square we are moving to is also unoccupied
    // or occupied by an opponent, then return true, otherwise return false.
    bool isOpponentOrEmpty =
            !Board::getBoard().squareAt(location.getX(), location.getY()).occupied()
                    || Board::getBoard().squareAt(location.getX(),
                            location.getY()).occupiedBy().color() != color();

    // Return true if the Square we are moving to is either empty or
    // an opponent and it is a clear vertical or horizontal.
    return isOpponentOrEmpty
            && (Board::getBoard().isClearVertical(this->location(), location)
                    || Board::getBoard().isClearHorizontal(this->location(),
                            location));
}

// Get the value of the Rook.
const int Rook::value() const
{
    // Return the Rook's value.
    return ROOK_VALUE;
}

// Display the Rook to the ostream passed as an argument.
void Rook::display(ostream& outStream) const
{
    // Display the Rook's color and the R representing the Rook.
    outStream << color() << 'R';
}

// Do nothing.
Rook::~Rook()
{

}

