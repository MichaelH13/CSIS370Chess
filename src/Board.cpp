#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include "Pawn.h"

// Constructor

// Create a board of the given dimension (i.e., NxN)
Board::Board(int dimension)
{
    // Create a vector of squares as a template that we can then copy
    // into our _board attribute, effectively populating the board with
    // copies of this row of squares - NOTE: this will not work if Square
    // objects need to know where they are...
    vector<Square*> rowTemplate(dimension);

    // Create all the rows in our vector of vectors holding pointers to
    // Squares.
    for (int i = 0; i < dimension; i++)
    {
        // Add the rowTemplate to the current index i on the Board.
        _board.push_back(rowTemplate);
    }

    // Iterate from 0 up to the dimension of the Board on the rows.
    for (int i = 0; i < dimension; i++)
    {
        // Iterate from 0 up to the dimension of the Board on the columns.
        for (int j = 0; j < dimension; j++)
        {
            // Create a new Square on the Board at the location (i,j).
            _board[i][j] = new Square(i, j);
        }
    }
}

// Accessors

// Return the square at x,y
Square& Board::squareAt(int x, int y)
{
    return *_board[x][y];
}

// Check for clear vertical
bool Board::isClearVertical(Square& from, Square& to) const
{
    bool isVerticalMove = !(from.getY() - to.getY());
    bool isClear = true;
    int biggerX = from.getX();
    int smallerX = to.getX();

    // If the original guess was wrong, swap them.
    if (smallerX > biggerX)
    {
        // Set biggerY and smallerY to be the
        // opposite of what they were previously.
        biggerX = to.getX();
        smallerX = from.getX();
    }

    // Iterate over the path from the top to the bottom (smaller to bigger).
    // Check each Square and as if it has a Piece on it.
    // Don't look at the starting Square (smallerX, from.getY())
    // because it is occupied by the Piece trying to move.
    for (int x = smallerX + 1; isClear && x < biggerX; x++)
    {
        // If a square is occupied, it will set isClear to false.
        isClear = !Board::getBoard().squareAt(x, from.getY()).occupied();
    }

    // Return true if it is a vertical move, the path is clear,
    // and the from Square is not the same Square as the to Square.
    return isVerticalMove && isClear && &from != &to;
}

// Check for clear horizontal
bool Board::isClearHorizontal(Square& from, Square& to) const
{
    bool isHorizontalMove = 0 == (from.getX() - to.getX());
    bool isClear = true;
    int biggerY = from.getY();
    int smallerY = to.getY();

    // If the original guess was wrong, swap them.
    if (smallerY > biggerY)
    {
        // Set biggerY and smallerY to be the
        // opposite of what they were previously.
        biggerY = to.getY();
        smallerY = from.getY();
    }

    // Iterate over the path from the right to the left (smaller to bigger).
    // Check each Square and as if it has a Piece on it.
    // Don't look at the starting Square (smallerX, from.getY())
    // because it is occupied by the Piece trying to move.
    for (int y = smallerY + 1; isClear && y < biggerY; y++)
    {
        // If a square is occupied, it will set isClear to false.
        isClear = !Board::getBoard().squareAt(from.getX(), y).occupied();
    }

    // Return true if it is a horizontal move, the path is clear,
    // and the from Square is not the same Square as the to Square.
    return isHorizontalMove && isClear && (&from != &to);
}

// Check for clear diagonal
bool Board::isClearDiagonal(Square& from, Square& to) const
{
    bool isDiagonal = ((abs(from.getX() - to.getX()))
            == ((abs(from.getY() - to.getY()))));
    bool isClear = true;
    Square* leftSquare = &from;
    Square* rightSquare = &to;
    int lowerBound;
    int upperBound;
    int rightBound;
    int currentX;
    int currentY;

    // If left is above, then switch the two Squares.
    if (leftSquare->getY() > rightSquare->getY())
    {
        // Set leftSquare and rightSquare to be the
        // opposite of what they were previously.
        leftSquare = &to;
        rightSquare = &from;
    }

    // If the left Square is below the right Square, then we will
    // iterate up and to the right to check the diagonal.
    if (leftSquare->getX() > rightSquare->getX())
    {
        // Set currentX and currentY such that they exclude
        // the Square we are technically starting at.
        // Set the upperBound and rightBound relative to the Board.
        currentX = leftSquare->getX() - 1;
        currentY = leftSquare->getY() + 1;
        upperBound = rightSquare->getX();
        rightBound = rightSquare->getY();

        // While we haven't found an obstruction, iterate along the path
        // until we reach the Square we are moving to.
        while (isClear && upperBound < currentX && rightBound > currentY)
        {
            // Check if the Square is clear, set isClear to false if it is not.
            isClear =
                    !Board::getBoard().squareAt(currentX, currentY).occupied();

            // Iterate/decrement currentX and currentY
            // to get to the next Square.
            currentX--;
            currentY++;
        }
    }
    // If the left Square is above the right Square, then we will
    // iterate up and to the right to check the diagonal.
    else
    {
        // Set currentX and currentY such that they exclude
        // the Square we are technically starting at.
        // Set the lowerBound and rightBound relative to the Board.
        currentX = leftSquare->getX() + 1;
        currentY = leftSquare->getY() + 1;
        lowerBound = rightSquare->getX();
        rightBound = rightSquare->getY();

        // While we haven't found an obstruction, iterate along the path
        // until we reach the Square we are moving to.
        while (isClear && currentX < lowerBound && currentY < rightBound)
        {
            // Check if the Square is clear, set isClear to false if it is not.
            isClear =
                    !Board::getBoard().squareAt(currentX, currentY).occupied();

            // Iterate currentX and currentY to get to the next Square.
            currentX++;
            currentY++;
        }
    }

    // Return true if the path is a diagonal and is a clear path as well.
    return isDiagonal && isClear;
}

// Display the board
void Board::display(ostream& output) const
{
    // Start our column marker at 'a'
    char columnMarker = 'a';

    // Iterate from 0 up to the dimension of the Board.
    for (int i = 0; i < getDimension(); i++)
    {
        // Output whitespace plus our character value to mark out the columns.
        output << "    " << columnMarker++;
    }

    // Output an end of line char to mark the end of the column markers.
    output << endl;

    // Display the rest of the Board.
    // Iterate from 0 up to the dimension of the Board on the rows.
    for (int i = 0; i < getDimension(); i++)
    {
        // Display a horizontal line through the Board.
        // Iterate from 0 up to the dimension of the Board on the columns times
        // 5 plus 3 to adjust for the Pieces and row markers.
        for (int j = 0; j < getDimension() * 5 + 3; j++)
        {
            // If we have not passed our row marker width, then output a space.
            if (j < 2)
            {
                // Output whitespace.
                output << " ";
            }
            // Else output a dash to delimit the columns/rows more clearly.
            else
            {
                // Output a dash.
                output << "-";
            }
        }

        // Output an end of line char to mark the end of the row/column markers.
        output << endl;

        // Output the dimension minus i (the row number) and a bar to mark the
        // beginning of the row.
        output << getDimension() - i << " |";

        // Display the current row of Squares.
        for (int j = 0; j < getDimension(); j++)
        {
            // Get the board and display the current Square.
            getBoard().squareAt(i, j).display(output);
        }

        // Output a bar to mark the end of the row and the dimension minus
        // i (the row number).
        output << " " << getDimension() - i << endl;
    }

    // Display a horizontal line at the bottom end of the Board.
    // Iterate from 0 up to the dimension of the Board on the columns times
    // 5 plus 3 to adjust for the Pieces and row markers.
    for (int j = 0; j < getDimension() * 5 + 3; j++)
    {
        // If we have not passed our row marker width, then output a space.
        if (j < 2)
        {
            // Output whitespace.
            output << " ";
        }
        // Else output a dash to delimit the columns/rows more clearly.
        else
        {
            // Output a dash.
            output << "-";
        }
    }

    // Output an end of line char to mark the end of the final row of the Board.
    output << endl;

    // Reset our column marker char to 'a'.
    columnMarker = 'a';

    // Iterate from 0 up to the dimension of the Board.
    for (int i = 0; i < getDimension(); i++)
    {
        // Output whitespace plus our character value to mark out the columns.
        output << "    " << columnMarker++;
    }

    // Output an end of line char to mark the end of the Board.
    output << endl;
}

// Get the reference to The Board.
Board& Board::getBoard()
{
    // If there is no Board, then create the Board.
    if (!Board::_theBoard)
    {
        // Create the Board.
        Board::_theBoard = new Board(_DIMENSION);
    }

    // Return the Board.
    return *_theBoard;
}

// Return dimensions of the board.
int Board::getDimension() const
{
    // Return the size of the board as the dimension.
    return _board.size();
}

// Print the board
ostream& operator<<(ostream& output, const Board& board)
{
    // Simply call our display method.
    board.display(output);
    return output;
}

// Fixed size of the board - change this value to use a different size
// board.
const int Board::_DIMENSION = 8;
Board* Board::_theBoard;
