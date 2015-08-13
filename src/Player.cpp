/*
 * Player.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

// Includes
#include "Game.h"
#include "Board.h"
#include "Square.h"
#include "Player.h"

#include <iostream>
#include <set>

// Construct a new Player.
Player::Player(string& name, King& myKing, set<Piece*>& myPieces) :
        _name(&name), _myKing(&myKing), _myPieces(myPieces), _capturedPieces(
                *(new set<Piece*>()))
{
}

// Have a Player make a move, if they can, otherwise return False.
bool Player::makeMove() const
{
    bool hasMoved = false;
    int x1, x2;
    char y1, y2;

    // While the Player hasn't entered a legal move, continue
    // trying to get a legal move.
    while (!hasMoved)
    {
        // Prompt the Player for their move.
        cout << endl << this->getName() << " please enter move: ";

        // Read in each character.
        cin >> y1;
        cin >> x1;
        cin >> y2;
        cin >> x2;

        // If the input was bad, then clear it and attempt to get the input again.
        if (cin.fail() || cin.bad())
        {
            cin.ignore(numeric_limits<std::streamsize>::max());
            cin.clear();
        }
        // Otherwise continue trying to make the move with the input given.
        else
        {
            // Adjust the coordinates given.
            x1 = Board::getBoard().getDimension() - x1;
            y1 = (y1 - 'a');
            x2 = Board::getBoard().getDimension() - x2;
            y2 = (y2 - 'a');

            // Validate the coordinate values.
            if (Game::isValidCoordinate(x1) && Game::isValidCoordinate(y1)
                    && Game::isValidCoordinate(x2)
                    && Game::isValidCoordinate(y2))
            {
                // If the Square is occupied, then ask the Piece there if it
                // can make the requested move.
                if (Board::getBoard().squareAt(x1, y1).occupied())
                {
                    // Try to make the move if we own the Piece, if it
                    // succeeds, set return value to be True.
                    if (this->myPieces().count(&(Board::getBoard().squareAt(x1, y1).occupiedBy())) && Board::getBoard().squareAt(x1, y1).occupiedBy().moveTo(((Player&) (*this)), Board::getBoard().squareAt(x2, y2)))
                    {
                        // Set hasMoved to true.
                        hasMoved = true;
                    }
                }
            }
        }
    }

    // Return hasMoved.
    return hasMoved;
}

// Get the name of the Player.
string& Player::getName() const
{
    // Return name.
    return *_name;
}

// Get the score of the Player.
const int Player::score()
{
    // Initialize the score to 0.
    int score = 0;

    // Iterate over each Piece we have captured and add it to our score.
    for (set<Piece*>::iterator i = _capturedPieces.begin();
            i != _capturedPieces.end(); i++)
    {
        // Add the value of the current captured Piece to our Score.
        score += (*i)->value();
    }

    // Return the score.
    return score;
}

// Capture a Piece.
void Player::capture(Piece& aPiece) const
{
    // Location of the Piece must be set to null before calling this method.
    // Add the Piece to our collection of Pieces.
    _capturedPieces.insert(&aPiece);
}

// Get a set of the Player's Pieces.
set<Piece*>& Player::myPieces() const
{
    // Return my Pieces.
    return _myPieces;
}

// Get the Player's King.
King& Player::myKing() const
{
    // Return my King.
    return *_myKing;
}

// Do nothing.
Player::~Player()
{

}
