#include "solveNQueens.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int runs;
// print the board to file
void printBoard(vector<string> currBoard) {
  ofstream aFile("every-state-of-the-board.csv");

  for (int i = 0; i < currBoard.size(); i++) {
    cout << currBoard[i];
    cout << endl;
  }
  cout << endl;

  aFile.close();
}

// takes in two ints for the location of a square and the currentBoard
// returns true if a queen can be placed there
bool SolveNQueens::valid(int col, int row, vector<string> currBoard) {
  // the size of the board
  int n = currBoard.size();

  // make sure there is not a queen already in your col
  for (int i = 0; i < n; i++) {
    if (currBoard[col][i] != '.') {
      return false;
    }
  }

  // make sure there is not a queen already in your row
  for (int i = 0; i < n; i++) {
    if (currBoard[i][row] != '.') {
      return false;
    }
  }

  int i = col;
  int j = row;
  while (i >= 0 && j >= 0) {
    if (currBoard[i][j] != '.') {
      return false;
    }
    i--;
    j--;
  }
  i = col;
  j = row;
  while (i >= 0 && j < n) {
    if (currBoard[i][j] != '.') {
      return false;
    }
    i--;
    j++;
  }

  return true;
}

void SolveNQueens::dfs(int indexC, int count, int n, vector<string> currBoard,
                       vector<vector<string>> &solutions) {
  // if count is equal to n then we have placed all the queens on the board and
  // the solution is valid
  if (count == n) {
    solutions.push_back(currBoard);
    return;
  }

  // if the current index is greater than the size of the board we have gone out
  // of bounds
  if (indexC >= n) {
    return;
  }

  // while
  for (int indexR = 0; indexR < n; indexR++) {
    // if the board is valid
    cout << ++runs << endl;
    if (valid(indexC, indexR, currBoard)) {
      currBoard[indexC][indexR] = 'Q';
      dfs(indexC + 1, count + 1, n, currBoard, solutions);
      currBoard[indexC][indexR] = '.';
    }
  }
}

vector<vector<string>> SolveNQueens::solveNQueens(int n) {
  vector<string> currBoard;
  string currColmn;
  vector<vector<string>> solutions;

  // mark every column in the row as empty
  for (int i = 0; i < n; i++) {
    currColmn += '.';
  }

  // add empty array to every row on board
  for (int i = 0; i < n; i++) {
    currBoard.push_back(currColmn);
  }

  //
  dfs(0, 0, n, currBoard, solutions);

  return solutions;
}

void solve1(int col, vector<string> &board, vector<vector<string>> &ans,
            vector<int> &leftRow, vector<int> &upperDiagonal,
            vector<int> &lowerDiagonal, int n) {
  if (col == n) {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 &&
        lowerDiagonal[row + col] == 0) {
      board[row][col] = 'Q';
      leftRow[row] = 1;
      upperDiagonal[n - 1 + col - row] = 1;
      lowerDiagonal[row + col] = 1;
      solve1(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
      board[row][col] = '.';
      leftRow[row] = 0;
      upperDiagonal[n - 1 + col - row] = 0;
      lowerDiagonal[row + col] = 0;
    }
  }
}

vector<vector<string>> SolveNQueens::solveFaster(int n) {

  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++) {
    board[i] = s;
  }

  // solve(0 , board , ans , n);

  vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0),
      lowerDiagonal(2 * n - 1, 0);
  solve1(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
  return ans;
}
