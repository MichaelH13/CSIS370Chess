README.txt
Author: Michael Higgins
Email: mhiggins13@georgefox.edu

1. This repository contains all files necessary to run a light-weight command-line version of Chess.
2. To compile and run these files as intended, the script "chess.sh" has been included.
3. Open up a command-line window and navigate to the directory containing both "chess.sh" and the "src" folder containing the source code for the game.
4. Enter the command `bash chess.sh` (you will may need to make sure this file is executable by using the command `chmod 755`).
5. The script will then compile and run the C++ source code.
6. The game is limited to keyboard input in the manner of first entering a letter (a-h) followed by a number (1-8) to indicate the piece you wish to move.
7. In the same manner as in 6) you will dictate the square you would like to move to (resulting in a move like `a2 a4` which would move the white pawn two spaces forward if we start a new game beforehand).
8. Disclaimers:
    a) All promotions (i.e. a pawn reaching the other side of the board without being captured) will promote the pawn to a queen.
    b) En Passant is not supported.
    c) Illegal moves will be ignored and a reprompt will occur for your move.
    d) You will be informed if your move would result in being in check after your move.
    e) The game does not exit upon checkmate. Use ctl+c to exit.
    f) This project is representative of the author's abilities while learning to use C++, therefore, any and all suggestions or criticisms are encouraged. 

