#ifndef SOLVENQUEENS_H_
#define SOLVENQUEENS_H_

#include <string>
#include <vector>

using namespace std;

class SolveNQueens {
public:
  bool isValidGen(vector<string> board, int row, int col);

  void recGen(vector<string> &board, vector<vector<string>> &solutions,
              int currRow, int n, int queens);

  vector<vector<string>> solveGeneral(int n, bool writeState);

  bool isValidOpt(vector<string> board, int row, int col);

  void recOpt(vector<string> &board, vector<vector<string>> &solutions,
              int currRow, int n, int queens);

  vector<vector<string>> solveOpt(int n, bool writeState);
};

#endif // SOLVENQUEENS_H_
