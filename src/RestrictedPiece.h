/*
 * RestrictedPiece.h
 *
 *  Created on: Mar 18, 2015
 *      Author: 1825794
 */

#ifndef RESTRICTEDPIECE_H_
#define RESTRICTEDPIECE_H_

// Includes
#include "Piece.h"

// Use the standard template library.
using namespace std;

/**
 * Class for representing a RestrictedPiece on a chess board.
 * A RestrictedPiece is a Piece that can additionally tell if it has moved yet
 * or not.
 */
class RestrictedPiece: public Piece
{
    public:
        // Constructor

        /**
         * Constructor for a chess Piece.
         * @param color the color of the Piece, defaults to an empty space.
         */
        RestrictedPiece(string color = "");

        /**
         * Returns True if the RestrictedPiece has moved yet.
         * @return True if the RestrictedPiece has moved yet.
         */
        const bool hasMoved() const;

        /**
         * Moves a Piece to the Square passed as an argument.
         * @param byPlayer The Player moving the Piece.
         * @param to The Square to move the Piece to.
         * @return True if the move was successful, False otherwise.
         */
        virtual bool moveTo(Player& byPlayer, Square& to);

        // Destructor

        /**
         * Destructor, remove any outstanding delegates.
         */
        ~RestrictedPiece();

    private:

        // Private attributes of a RestrictedPiece.
        // _moved is a boolean representing whether or not the Piece has moved.
        bool _moved;
};

#endif /* RESTRICTEDPIECE_H_ */
