/*
 * Game.h
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

#ifndef GAME_H_
#define GAME_H_

// Includes
#include "Player.h"

/**
 * Class to represent turn taking between Players. A Game can tell whos turn it
 * is, who is the opponent of a Player, and setup a Game.
 */
class Game
{
    public:
        // Constructor

        /**
         * Construct a new Game.
         */
        Game();

        // Accessors

        /**
         * Return a reference to the opponent of the Player reference passed
         * as an argument.
         * @param player A reference to the Player to get the opponent of.
         * @return The opponent of the Player passed as an argument.
         */
        const Player& opponentOf(Player& player) const;

        /**
         * Return the next Player in the Game.
         * @return The next Player in the Game.
         */
        const Player& getNextPlayer();

        /**
         * Setup a new Game.
         */
        void initialize();

        /**
         * Return true if the coordinate provided is valid.
         * @param coordinate The coordinate to check.
         * @return true if the coordinate provided is valid.
         */
        static bool isValidCoordinate(int coordinate);

        /**
         * Destructor, does nothing.
         */
        ~Game();

        static Game CHESS;

    private:

        // Private attributes of a Game.
        // _white is a pointer to the Player with the white Pieces.
        // _black is a pointer to the Player with the black Pieces.
        // _currentPlayer is a pointer to the Player who's turn it is.
        Player* _white;
        Player* _black;
        Player* _currentPlayer;
};

#endif /* GAME_H_ */
