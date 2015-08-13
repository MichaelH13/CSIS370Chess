/*
 * Game.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

// Includes
#include "Game.h"
#include "Board.h"
#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"

#include <vector>

// Construct a new game, note that the game must be initialized before Playing.
Game::Game()
{
    _white = NULL;
    _black = NULL;
    _currentPlayer = NULL;
}

// Return the opponent of the player passed as an argument.
const Player& Game::opponentOf(Player& player) const
{
    // If the address of the player argument is equal to our white pointer
    // then return the black Player.
    if (&player == _white)
    {
        // Return the black Player.
        return *_black;
    }
    // If the address of the player argument is not equal to our white pointer
    // then return the white Player.
    else
    {
        // Return the white Player.
        return *_white;
    }
}

// Return a reference to the next Player.
const Player& Game::getNextPlayer()
{
    // If the current Player is white then switch the current Player
    // to be black and return the black Player.
    if (_currentPlayer == _white)
    {
        // Switch the current Player to be black and return the black Player.
        _currentPlayer = _black;
    }
    // Else the current Player is black so switch the current Player
    // to be white and return the white Player.
    else
    {
        // Switch the current Player to be white and return the white Player.
        _currentPlayer = _white;
    }

    return *_currentPlayer;
}

// Setup the game.
void Game::initialize()
{
    int row = 0;
    int column = 0;
    set<Piece*>* whitePieces = new set<Piece*>();
    set<Piece*>* blackPieces = new set<Piece*>();
    King* blackKing;
    King* whiteKing;

    // Iterate over the columns, placing Pieces in the correct rows.
    for (column = 0; column < Board::getBoard().getDimension(); column++)
    {
        // Set the Pieces in their correct locations.

        // Set the black Pawns, and tell them their Square, and add them
        // to the appropriate Piece set.
        Board::getBoard().squareAt(row + 1, column).setOccupier(new Pawn("B"));

        Board::getBoard().squareAt(row + 1, column).occupiedBy().setLocation(
                &(Board::getBoard().squareAt(row + 1, column)));

        blackPieces->insert(
                &(Board::getBoard().squareAt(row + 1, column).occupiedBy()));

        // Set the white Pawns, and tell them their Square, and add them
        // to the appropriate Piece set.
        Board::getBoard().squareAt(row + 6, column).setOccupier(new Pawn("W"));

        Board::getBoard().squareAt(row + 6, column).occupiedBy().setLocation(
                &(Board::getBoard().squareAt(row + 6, column)));

        whitePieces->insert(
                &(Board::getBoard().squareAt(row + 6, column).occupiedBy()));
    }

    // Reset column to manually place special pieces.
    column = 0;

    // Set the black Rooks, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row, column).setOccupier(new Rook("B"));
    Board::getBoard().squareAt(row, column).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column)));

    Board::getBoard().squareAt(row, column + 7).setOccupier(new Rook("B"));
    Board::getBoard().squareAt(row, column + 7).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 7)));

    blackPieces->insert(&(Board::getBoard().squareAt(row, column).occupiedBy()));
    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 7).occupiedBy()));

    // Set the white Rooks, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row + 7, column).setOccupier(new Rook("W"));
    Board::getBoard().squareAt(row + 7, column).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column)));

    Board::getBoard().squareAt(row + 7, column + 7).setOccupier(new Rook("W"));
    Board::getBoard().squareAt(row + 7, column + 7).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 7)));

    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column).occupiedBy()));

    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 7).occupiedBy()));

    // Set the black Knights, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row, column + 1).setOccupier(new Knight("B"));
    Board::getBoard().squareAt(row, column + 1).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 1)));

    Board::getBoard().squareAt(row, column + 6).setOccupier(new Knight("B"));
    Board::getBoard().squareAt(row, column + 6).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 6)));

    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 1).occupiedBy()));
    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 6).occupiedBy()));

    // Set the white Knights, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row + 7, column + 1).setOccupier(
            new Knight("W"));
    Board::getBoard().squareAt(row + 7, column + 1).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 1)));

    Board::getBoard().squareAt(row + 7, column + 6).setOccupier(
            new Knight("W"));
    Board::getBoard().squareAt(row + 7, column + 6).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 6)));

    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 1).occupiedBy()));
    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 6).occupiedBy()));

    // Set the black Bishops, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row, column + 2).setOccupier(new Bishop("B"));
    Board::getBoard().squareAt(row, column + 2).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 2)));

    Board::getBoard().squareAt(row, column + 5).setOccupier(new Bishop("B"));
    Board::getBoard().squareAt(row, column + 5).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 5)));

    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 2).occupiedBy()));
    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 5).occupiedBy()));

    // Set the white Bishops, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row + 7, column + 2).setOccupier(
            new Bishop("W"));
    Board::getBoard().squareAt(row + 7, column + 2).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 2)));

    Board::getBoard().squareAt(row + 7, column + 5).setOccupier(
            new Bishop("W"));
    Board::getBoard().squareAt(row + 7, column + 5).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 5)));

    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 2).occupiedBy()));
    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 5).occupiedBy()));

    // Set the black King and Queen, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row, column + 3).setOccupier(new Queen("B"));
    Board::getBoard().squareAt(row, column + 3).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 3)));

    Board::getBoard().squareAt(row, column + 4).setOccupier(new King("B"));
    Board::getBoard().squareAt(row, column + 4).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row, column + 4)));

    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 3).occupiedBy()));
    blackPieces->insert(
            &(Board::getBoard().squareAt(row, column + 4).occupiedBy()));
    blackKing =
            (King*) &(Board::getBoard().squareAt(row, column + 4).occupiedBy());

    // Set the white King and Queen, and tell them their Square, and add them
    // to the appropriate Piece set.
    Board::getBoard().squareAt(row + 7, column + 3).setOccupier(new Queen("W"));
    Board::getBoard().squareAt(row + 7, column + 3).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 3)));

    Board::getBoard().squareAt(row + 7, column + 4).setOccupier(new King("W"));
    Board::getBoard().squareAt(row + 7, column + 4).occupiedBy().setLocation(
            &(Board::getBoard().squareAt(row + 7, column + 4)));

    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 3).occupiedBy()));
    whitePieces->insert(
            &(Board::getBoard().squareAt(row + 7, column + 4).occupiedBy()));
    whiteKing =
            (King*) &(Board::getBoard().squareAt(row + 7, column + 4).occupiedBy());

    // Create the Players for the game and set the current Player to be black.
    _black = new Player(*(new string("Black")), *blackKing, *blackPieces);
    _white = new Player(*(new string("White")), *whiteKing, *whitePieces);
    _currentPlayer = _black;
}

// Check Coordinate against the Board Dimension.
bool Game::isValidCoordinate(int coordinate)
{
    // Return true if the coordinate is greater than 0 and less than
    // the size of the dimension of the Board.
    return coordinate >= 0 && coordinate < Board::getBoard().getDimension();
}

Game Game::CHESS = *(new Game());

// Do nothing.
Game::~Game()
{

}

