/*
 * Piece.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

// Includes
#include "Board.h"
#include "Square.h"
#include "Player.h"
#include "Game.h"

// Construct a new Piece.
Piece::Piece(string color) :
        _color(color)
{
    _location = NULL;
}

// Make a move by a Player to a Square and return if the move was made.
bool Piece::moveTo(Player& byPlayer, Square& to)
{
    // Default to return false.
    bool hasMoved = false;
    bool inCheck = false;
    Piece* capturePiece;
    Square& from = this->location();

    // If we own the Piece being requested to move then
    // check if we can move it to the requested Square.
    if (byPlayer.myPieces().find(this) != byPlayer.myPieces().end())
    {
        // Check if the Piece can move to the Square
        // provided, then set hasMoved to true.
        if (canMoveTo(to))
        {
            // If it is occupied, then we will capture this Piece before moving
            // the other Piece.
            if (Board::getBoard().squareAt(to.getX(), to.getY()).occupied())
            {
                // Hold on to the Piece we are attempting to capture.
                capturePiece = &(Board::getBoard().squareAt(to.getX(),
                        to.getY()).occupiedBy());
                capturePiece->setLocation(NULL);
            }

            // Tell the new Square that a Piece has been set on it.
            Board::getBoard().squareAt(to.getX(), to.getY()).setOccupier(
                    (Piece*) this);

            // Tell the Square the Piece has moved to the new Square.
            this->location().setOccupier(NULL);

            // Tell the Piece it has moved to the new Square.
            this->setLocation(
                    &(Board::getBoard().squareAt(to.getX(), to.getY())));

            // If we are not in check, then proceed to capture the Piece.
            for (set<Piece*>::iterator i =
                    Game::CHESS.opponentOf(byPlayer).myPieces().begin();
                    !inCheck
                            && i
                                    != Game::CHESS.opponentOf(byPlayer).myPieces().end();
                    i++)
            {
                // If the Piece hasn't been captured then ask it if
                // it can move to where our King is.
                if ((*i)->isOnSquare())
                {
                    // If the current Piece in the other Player's
                    // Piece can move where our King is, then set
                    // inCheck to true, otherwise false.
                    inCheck = (*i)->canMoveTo(byPlayer.myKing().location());
                }
            }

            // If we are not in check, then the move has been made.
            // Capture the Piece saved (if a Piece was on the to Square)
            // and set hasMoved to be true.
            if (!inCheck)
            {
                // Capture the Piece we saved, if we saved a Piece.
                if (capturePiece)
                {
                    // Capture the Piece that used to occupy
                    // the Square we are moving to.
                    byPlayer.capture(*capturePiece);
                }

                // Set hasMoved to true.
                hasMoved = true;
            }
            // Reverse the move because we are in check.
            else
            {
                // Tell the Square the Piece has returned to the
                // old Square (if there was one).
                to.setOccupier(capturePiece);

                // If there was a Piece there, let the Piece know where it is.
                if (to.occupied())
                {
                    to.occupiedBy().setLocation(&to);
                }

                // Tell the old Square that its old friend
                // Piece has been set back on it.
                Board::getBoard().squareAt(from.getX(), from.getY()).setOccupier(
                        (Piece*) this);

                // Tell the Piece it has moved back to the old Square.
                this->setLocation(
                        &(Board::getBoard().squareAt(from.getX(), from.getY())));

                cout << "That move would leave you in check." << endl;
            }
        }
    }
    // Display a color error message.
    else
    {
        cout << "You may only move the Piece(s) with a '"
                << byPlayer.myKing().color() << "' in their name." << endl;
    }

    // Return hasMoved.
    return hasMoved;
}

// Return the color of the Piece.
const string Piece::color() const
{
    // Return the color of the Piece.
    return _color;
}

// Set the location of the Piece.
const void Piece::setLocation(Square* square)
{
    // Set the location of the Piece.
    _location = square;
}

// Find out if a Piece is on a Square.
bool Piece::isOnSquare() const
{
    // Return pointer to location, which is true if
    // we have a pointer, false otherwise.
    return _location;
}

// Get the location of the Piece.
Square& Piece::location() const
{
    // Return the location of the Piece.
    return *_location;
}

// Does nothing.
Piece::~Piece()
{
}
