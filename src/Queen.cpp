/*
 * Queen.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

// Includes
#include "Queen.h"
#include "Board.h"

// Construct a new Queen Piece.
Queen::Queen(string color) :
        Piece(color)
{

}

// Check if the Queen can move to the location passed as an argument.
bool Queen::canMoveTo(Square& location) const
{
    // If the Square we are moving to is either a clear vertical or
    // horizontal or diagonal and the Square we are moving to is also unoccupied
    // or occupied by an opponent, then return true, otherwise return false.
    bool isOpponentOrEmpty =
            !Board::getBoard().squareAt(location.getX(), location.getY()).occupied()
                    || Board::getBoard().squareAt(location.getX(),
                            location.getY()).occupiedBy().color() != color();

    return isOpponentOrEmpty
            && (Board::getBoard().isClearDiagonal(this->location(), location)
                    || Board::getBoard().isClearHorizontal(this->location(),
                            location)
                    || Board::getBoard().isClearVertical(this->location(),
                            location));
}

// Get the value of the Queen.
const int Queen::value() const
{
    // Return the Queen's value.
    return QUEEN_VALUE;
}

// Display the Queen to the ostream passed as an argument.
void Queen::display(ostream& outStream) const
{
    // Display the Queen's color and the Q representing the Queen.
    outStream << color() << "Q";
}

// Do nothing.
Queen::~Queen()
{

}
