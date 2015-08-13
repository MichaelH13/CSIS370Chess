/*
 * Player.h
 *
 *  Created on: Mar 16, 2015
 *      Author: 1825794
 */

#ifndef PLAYER_H_
#define PLAYER_H_

// Includes
#include "Piece.h"
#include "King.h"

#include <string>
#include <set>

// Using the standard template library.
using namespace std;

/**
 * Class to represent a player in the game of Chess.
 * A player can make a move, tell you its name, tell you its score, capture
 * a Piece, give you a set of all the Pieces it owns, and tell you where its
 * King Piece is.
 */
class Player
{
    public:
        // Constructor

        /**
         * Constructs a new Player with the name, King, and Pieces all passed
         * as arguments.
         * @param name The name of the Player.
         * @param myKing The pointer to the King of the Player.
         * @param myPieces The pointer to the set of Pieces of the Player.
         */
        Player(string& name, King& myKing, set<Piece*>& myPieces);

        /**
         * Returns True if the Player can make/has made a move, otherwise False.
         * @return True if the Player can make/has made a move, otherwise False.
         */
        bool makeMove() const;

        /**
         * Returns a reference to the name of the PLayer.
         * @return A reference to the name of the Player.
         */
        string& getName() const;

        /**
         * Returns the score of the Player.
         * @return The score of the Player.
         */
        const int score();

        /**
         * Captures the Piece passed as an argument and adds it to the set
         * of captured Pieces.
         */
        void capture(Piece& aPiece) const;

        /**
         * Returns a reference to the Pieces of the Player.
         * @return A reference to the Pieces of the Player.
         */
        set<Piece*>& myPieces() const;

        /**
         * Returns a reference to the Player's King.
         * @return A reference to the Playre's King.
         */
        King& myKing() const;

        /**
         * Destructor, not used.
         */
        ~Player();

    private:

        // Private attributes of a Player.
        // _name is the name of the Player.
        // _myPieces is a pointer to the Pieces of the Player.
        // _capturedPieces is a pointer to the Pieces the Player has captured.
        // _myKing is a pointer to the King of the Player.
        string* _name;
        King* _myKing;
        set<Piece*>& _myPieces;
        set<Piece*>& _capturedPieces;
};

#endif /* PLAYER_H_ */
