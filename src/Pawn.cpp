/*
 * Pawn.cpp
 *
 *  Created on: Mar 19, 2015
 *      Author: Michael
 */

// Includes
#include "Board.h"
#include "Pawn.h"
#include "Queen.h"

// Construct a new Pawn Piece.
Pawn::Pawn(string color) : RestrictedPiece(color)
{
    _delegate = NULL;
}

// Get the value of the Pawn.
const int Pawn::value() const
{
    // Implementation may be changed later due to delegate Piece.
    // Return the value of the Pawn.
    return PAWN_VALUE;
}

// Check if the Pawn can move to the location passed as an argument.
bool Pawn::canMoveTo(Square& location) const
{
    // Default isValidMove to false.
    bool isValidMove = false;

    // If we have a delegate Piece, then ask it if we can move to the location.
    if (_delegate)
    {
        // Ask the delegate Piece if we can move to the location.
        isValidMove = _delegate->canMoveTo(location);
    }
    // If the requested Square is occupied, then allow a diagonal move
    // relative to our current position.
    else if (Board::getBoard().squareAt(location.getX(), location.getY()).occupied())
    {
        // If the absolute value of the difference between the column (Y)
        // position and the column (Y) end position is 1, then we must be
        // making a diagonal-type move.
        if (abs(this->location().getY() - location.getY()) == 1)
        {
            // If the absolute value of the difference between the row (X)
            // position and the row (X) position is 1, then we must be
            // making a valid diagonal-type move.
            if (abs(this->location().getX() - location.getX()) == 1)
            {
                // Valid move, taking the Piece at the Square passed.
                isValidMove = true;
            } // Else not valid, can't move purely horizontally, ever.
        } // We can not move diagonally to an occupied Square without capturing the Piece.
    }
    // Else we are moving to an empty Square.
    else
    {
        // If we haven't moved yet, then we can move two Squares.
        // Make sure we are moving only 2 Squares vertically and 0 Squares
        // horizontally. Then check if the path is a clear vertical.
        if (!hasMoved() && abs(this->location().getX() - location.getX()) == 2
                && abs(this->location().getY() - location.getY()) == 0
                && Board::getBoard().isClearVertical(this->location(),
                        location))
        {
            // Valid move, two Squares.
            isValidMove = true;
        }
        // If the absolute value of the difference between the X-start
        // position and the X-end position is equal to 1,
        // then we must be making a valid one Square move.
        else if (abs(this->location().getX() - location.getX()) == 1
                && abs(this->location().getY() - location.getY()) == 0)
        {
            // Valid move, single Square.
            isValidMove = true;
        }
    }

    // If we don't have a delegate, then check the
    // direction that the Pawn is moving.
    if (!_delegate)
    {
        // Return true if the move is valid and if either the Piece is White
        // and moving up the board or Black and moving down the Board.
        return isValidMove
                && (((color() == "W")
                        && ((this->location().getX() - location.getX()) >= 1))
                        || ((color() == "B")
                                && ((this->location().getX() - location.getX())
                                        <= -1)));
    }

    // Return isValidMove.
    return isValidMove;
}

// Check if the Pawn can move to the location and create a new delegate if we
// have reached the edge of the Board and do not already have a delegate.
bool Pawn::moveTo(Player& byPlayer, Square& to)
{
    // Call a parent method to do the majority of the work and save the result.
    bool hasMoved = RestrictedPiece::moveTo(byPlayer, to);

    // If we don't have a delegate and the move was successful and we are
    // now on an edge of the Board, then create a new delegate.
    if (!_delegate && hasMoved
            && (this->location().getX() == 0
                    || this->location().getX() + 1
                            == Board::getBoard().getDimension()))
    {
        // Create a new delegate and let it know where it is.
        _delegate = new Queen(this->color());
        setLocation(&(this->location()));
    }

    // Return the result of the move.
    return hasMoved;
}

// Display the Pawn to the ostream passed as an argument.
void Pawn::display(ostream& outStream) const
{
    // If we have a delegate, display the delegate,
    // otherwise display ourself normally.
    if (_delegate)
    {
        // Call the delegates display method.
        _delegate->display(outStream);
    }
    else
    {
        // Output the color of the Piece and a 'P'
        outStream << color() << 'P';
    }
}

// Set the location of the Piece.
const void Pawn::setLocation(Square* square)
{
    // Set the location of the Piece and its delegate, if it has one.
    if (_delegate)
    {
        // Set the location of the delegate Piece.
        _delegate->setLocation(square);
    }

    // Now normally set the location of the current Pawn.
    Piece::setLocation(square);
}

// Remove whatever object we were pointing to.
Pawn::~Pawn()
{
    delete _delegate;
}

