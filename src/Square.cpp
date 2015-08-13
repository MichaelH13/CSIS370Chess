/*
 * Square.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

// Includes
#include "Square.h"

// Construct a new Square at X coordinate x and Y coordinate y.
// Set the pointer to the Square's occupant to null.
Square::Square(int x, int y)
{
    _x = x;
    _y = y;
    _piece = NULL;
}

// Get the X coordinate the Square is at.
int Square::getX() const
{
    // Return x.
    return _x;
}

// Get the Y coordinate the Square is at.
int Square::getY() const
{
    // Return y.
    return _y;
}

// Find out if the square is occupied.
bool Square::occupied() const
{
    // Return the pointer to the Piece, if it is null it will return
    // False, True otherwise.
    return _piece;
}

// Get the Piece that occupies this Square.
Piece& Square::occupiedBy() const
{
    // Dreference the Piece pointer to get the Piece occupying the Square.
    return *_piece;
}

// Set the occupier of the Square to the be Piece reference passed as
// an argument.
void Square::setOccupier(Piece* piece)
{
    // Set the pointer to the Piece to be the address of the reference.
    _piece = piece;
}

// Display the Square's contents.
void Square::display(ostream& outStream) const
{
    // Output whitespace.
    outStream << " ";

    // If the Square is occupied, then display the occupier of the Square.
    if (occupied())
    {
        // Display the occupier of the Square.
        occupiedBy().display(outStream);
    }
    // If the Square is not occupied, then display whitespace instead.
    else
    {
        // Display whitespace instead.
        outStream << "  ";
    }

    // Output whitespace followed by a bar to delineate the verticals on
    // the Square.
    outStream << " |";
}
