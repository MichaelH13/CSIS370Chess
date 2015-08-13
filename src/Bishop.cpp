/*
 * Bishop.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: 1825794
 */

// Includes
#include "Bishop.h"
#include "Board.h"

// Construct a new Bishop Piece.
Bishop::Bishop(string color) :
        Piece(color)
{

}

// Get the value of the Bishop.
const int Bishop::value() const
{
    // Return the value of the Bishop.
    return BISHOP_VALUE;
}

// Check if the Bishop can move to the location passed as an argument.
bool Bishop::canMoveTo(Square& location) const
{
    // If the Square we are moving to is either a clear vertical or
    // horizontal and the Square we are moving to is also unoccupied
    // or occupied by an opponent, then return true, otherwise return false.
    bool isOpponentOrEmpty =
            !Board::getBoard().squareAt(location.getX(), location.getY()).occupied()
                    || Board::getBoard().squareAt(location.getX(),
                            location.getY()).occupiedBy().color() != color();

    // Return true if the Square we are moving to is either empty or
    // an opponent and it is a clear diagonal.
    return isOpponentOrEmpty
            && Board::getBoard().isClearDiagonal(this->location(), location);
}

// Display the Bishop to the ostream passed as an argument.
void Bishop::display(ostream& outStream) const
{
    // Display the color of the Bishop and the B representing the Bishop.
    outStream << color() << 'B';
}

// Do nothing.
Bishop::~Bishop()
{

}

