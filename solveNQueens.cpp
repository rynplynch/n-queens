#include "solveNQueens.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int runs;
ofstream aFile("every-state-of-the-board.csv");
// print the board to file
// change the current square so we can see what is being exampined then change
// it back
void printBoard(vector<string> &currBoard, int indexR, int indexC) {

  currBoard[indexR][indexC] = '$';
  for (int i = 0; i < currBoard.size(); i++) {
    aFile << currBoard[i];
    aFile << endl;
  }
  currBoard[indexR][indexC] = '.';
  aFile << endl;
}

// takes in two ints for the location of a square and the currentBoard
// returns true if a queen can be placed there
bool SolveNQueens::isValidGen(vector<string> board, int row, int col) {
  // the size of the board
  int n = board.size();

  // make sure there is not a queen already in your col
  for (int i = 0; i < n; i++) {
    if (board[i][col] != '.') {
      return false;
    }
  }

  // make sure there is not a queen already in your row
  for (int i = 0; i < n; i++) {
    if (board[row][i] != '.') {
      return false;
    }
  }

  int rowUp = row;
  int rowDown = row;
  int diagonalLTop = col;
  int diagonalLBot = col;
  int diagonalRTop = col;
  int diagonalRBot = col;

  // move through every row
  for (int i = 0; i < n; i++) {
    // check squares to top left of square
    if (diagonalLTop >= 0 && rowUp >= 0 && board[rowUp][diagonalLTop] != '.') {
      return false;
    }

    // check square to top right of square
    if (diagonalRTop < n && rowUp >= 0 && board[rowUp][diagonalRTop] != '.') {
      return false;
    }

    // check squares to bot left of squares
    if (diagonalLBot >= 0 && rowDown < n &&
        board[rowDown][diagonalLBot] != '.') {
      return false;
    }

    // check squares to bot right of squares
    if (diagonalRBot < n && rowDown < n &&
        board[rowDown][diagonalRBot] != '.') {
      return false;
    }
    rowUp--;
    rowDown++;
    diagonalRTop++;
    diagonalRBot++;
    diagonalLBot--;
    diagonalLTop--;
  }

  return true;
}

void SolveNQueens::recGen(vector<string> &board,
                          vector<vector<string>> &solutions, int currRow, int n,
                          int queens) {
  // if count is equal to n then we have placed all the queens on the board and
  // the solution is valid
  if (queens == n) {
    solutions.push_back(board);
    return;
  }

  // if the current index is greater than the size of the board we have gone out
  // of bounds
  if (currRow >= n) {
    return;
  }

  // this call of the function will try to place a queen in every square of this
  // row
  for (int currCol = 0; currCol < n; currCol++) {
    // print the board in its current state
    if (aFile.is_open()) {
      printBoard(board, currRow, currCol);
    }

    // check to see if this spot on the board is legal
    if (isValidGen(board, currRow, currCol)) {
      queens++;
      // we know its good so we place a queen
      board[currRow][currCol] = 'Q';
      // recursively call this function to find the next legal position in the
      // next row
      recGen(board, solutions, currRow + 1, n, queens);

      queens--;
      // if we come back here a solution was not found so remove the queen we
      // just placed
      board[currRow][currCol] = '.';
    }
  }
}

vector<vector<string>> SolveNQueens::solveGeneral(int n, bool writeState) {
  vector<string> board;
  string currColmn;
  vector<vector<string>> solutions;

  if (!writeState) {
    aFile.close();
  }
  // mark every column in the row as empty
  for (int i = 0; i < n; i++) {
    currColmn += '.';
  }

  // add empty array to every row on board
  for (int i = 0; i < n; i++) {
    board.push_back(currColmn);
  }

  recGen(board, solutions, 0, n, 0);
  return solutions;
}

bool SolveNQueens::isValidOpt(vector<string> board, int row, int col) {
  int n = board.size();
  int diagonalL = col;
  int diagonalR = col;

  while (row >= 0) {
    // check square above this square
    if (board[row][col] != '.') {
      return false;
    }

    // check square diagonal to the left
    if (diagonalL >= 0 && board[row][diagonalL] != '.') {
      return false;
    }

    // check square diagonal to the right
    if (diagonalR < n && board[row][diagonalR] != '.') {
      return false;
    }

    // move to next row
    row--;
    diagonalL--;
    diagonalR++;
  }

  return true;
}
void SolveNQueens::recOpt(vector<string> &board,
                          vector<vector<string>> &solutions, int currRow, int n,
                          int queens) {
  // if we have placed all the queens then this is a valid solution
  if (queens == n) {
    solutions.push_back(board);
    return;
  }

  // if the current row equals n we have reach the end of the board
  if (currRow >= n) {
    return;
  }

  // loop through every column in the current row
  for (int currCol = 0; currCol < n; currCol++) {
    if (aFile.is_open()) {
      printBoard(board, currRow, currCol);
    }
    // check diagonally to the left and right
    // check directly above
    if (isValidOpt(board, currRow, currCol)) {
      queens++;
      // if there are no queens we can place one
      board[currRow][currCol] = 'Q';

      // call the functions again to move on to the next row
      recOpt(board, solutions, currRow + 1, n, queens);

      queens--;
      // if we return here then we need to remove the queen and try another spot
      board[currRow][currCol] = '.';
    }
  }
}

vector<vector<string>> SolveNQueens::solveOpt(int n, bool writeState) {
  vector<string> board;
  string currColmn;
  vector<vector<string>> solutions;

  if (!writeState) {
    aFile.close();
  }

  // mark every column in the row as empty
  for (int i = 0; i < n; i++) {
    currColmn += '.';
  }

  // add empty array to every row on board
  for (int i = 0; i < n; i++) {
    board.push_back(currColmn);
  }

  recOpt(board, solutions, 0, n, 0);
  return solutions;
}
