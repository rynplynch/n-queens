#include "solveNQueens.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// test for the leet code solution
void leetTestGeneral(bool writeState) {
  // answer from running the solution
  vector<vector<string>> response;

  // what we expect the answer to be
  vector<vector<string>> checker;
  vector<string> answer0 = {".Q..", "...Q", "Q...", "..Q."};
  vector<string> answer1 = {"..Q.", "Q...", "...Q", ".Q.."};
  checker.push_back(answer0);
  checker.push_back(answer1);

  // what the leetcode solution returns
  SolveNQueens solver = SolveNQueens();
  response = solver.solveGeneral(4, writeState);

  // checking the response
  assert(response.size() == checker.size());
  assert(response[0] == checker[0]);
  assert(response[1] == checker[1]);
}

// test for the leet code solution
void leetTestOpt(bool writeState) {
  // answer from running the solution
  vector<vector<string>> response;

  // what we expect the answer to be
  vector<vector<string>> checker;
  vector<string> answer0 = {".Q..", "...Q", "Q...", "..Q."};
  vector<string> answer1 = {"..Q.", "Q...", "...Q", ".Q.."};
  checker.push_back(answer0);
  checker.push_back(answer1);

  // what the leetcode solution returns
  SolveNQueens solver = SolveNQueens();
  response = solver.solveOpt(4, writeState);

  // checking the response
  assert(response.size() == checker.size());
  assert(response[0] == checker[0]);
  assert(response[1] == checker[1]);
}

int main() {
  leetTestGeneral(true);
  // leetTestOpt(false);

  return 0;
}
