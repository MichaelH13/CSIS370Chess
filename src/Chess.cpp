//============================================================================
// Name        : Chess.cpp
// Author      : 1825794
// Version     : 0.1
// Description : Chess Prototype, Ansi-style
//============================================================================

// Includes
#include "Game.h"
#include "Board.h"
#include "Player.h"

#include <iostream>

// Using the standard template library.
using namespace std;

/**
 * Begin a game of Chess, setup and display the Board, accept moves from Players.
 */
int main()
{
    // Set canMove to true, this will be our looping variable.
    bool canMove = true;

    // Setup the game.
    Game::CHESS.initialize();

    // The game loop, continue until ctrl+c interrupts.
    while (canMove)
    {
        // Display the board.
        Board::getBoard().display(cout);

        // Set canMove to be the result of a Player trying to make a move.
        canMove = Game::CHESS.getNextPlayer().makeMove();
    }

    // Exit the program.
    return 0;
}

