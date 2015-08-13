/*
 * RestrictedPiece.cpp
 *
 *  Created on: Mar 18, 2015
 *      Author: 1825794
 */

// Includes
#include "RestrictedPiece.h"
#include "Piece.h"

#include <iostream>

// Construct a new RestrictedPiece.
RestrictedPiece::RestrictedPiece(string color) :
        Piece(color)
{
    // Initialize moved to false since it is a new RestrictedPiece.
    _moved = false;
}

// Return if the RestrictedPiece has moved or not.
const bool RestrictedPiece::hasMoved() const
{
    // Return moved.
    return _moved;
}

// Move the Player's Piece to the Square passed as a reference.
bool RestrictedPiece::moveTo(Player& byPlayer, Square& to)
{
    // Default return value to be false.
    bool hasMoved = false;

    // Call our parent method to make the move.
    // Afterwards we will do a little extra work.
    hasMoved = Piece::moveTo(byPlayer, to);

    // If we have not moved yet, then set _moved to true.
    if (hasMoved && !this->hasMoved())
    {
        // Set moved to true.
        _moved = true;
    }

    // Return true if the move was made, false otherwise.
    return hasMoved;
}

// Do nothing.
RestrictedPiece::~RestrictedPiece()
{
}

