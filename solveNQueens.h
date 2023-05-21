#ifndef SOLVENQUEENS_H_
#define SOLVENQUEENS_H_

#include <string>
#include <vector>

using namespace std;

class SolveNQueens {
public:
  bool valid(int row, int col, vector<string> arr);

  void dfs(int index, int count, int n, vector<string> arr,
           vector<vector<string>> &ans);

  vector<vector<string>> solveNQueens(int n);
  vector<vector<string>> solveFaster(int n);
};

#endif // SOLVENQUEENS_H_
