#include "solveNQueens.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// test for the leet code solution
void leetTest() {
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
  response = solver.solveNQueens(4);

  // checking the response
  assert(response.size() == checker.size());
  assert(response[0] == checker[0]);
  assert(response[1] == checker[1]);

  response.clear();
  response = solver.solveFaster(4);

  // checking the response
  assert(response.size() == checker.size());
}

void generateCSV(int k) {
  ofstream aFile("n-queens-solutions.csv");
  vector<vector<string>> solutions;
  SolveNQueens *solver = new SolveNQueens();

  // take the solutions returned by solveNQueens for the value k and put it on a
  // newline in the csv file
  for (int i = 1; i <= k; i++) {
    // remove answers from last iteration
    solutions.clear();

    // get answers for this value of k
    solutions = solver->solveNQueens(i);

    // write the number of solutions to file
    aFile << solutions.size() << endl;

    // return output to console as well
    cout << solutions.size() << endl;
  }

  delete solver;
  aFile.close();
}

void genCSVForInt(int k) {
  ofstream aFile("solutions-for-n-queens.csv");
  vector<vector<string>> solutions;
  SolveNQueens *solver = new SolveNQueens();

  solutions = solver->solveNQueens(k);
  // take the solutions returned by solveNQueens for the value k and put it on a
  // newline in the csv file
  for (int i = 0; i < solutions.size(); i++) {
    // write the number of solutions to file
    for (int j = 0; j < solutions[i].size(); j++) {

      aFile << solutions[i][j] << endl;
    }
    aFile << endl;
  }

  delete solver;
  aFile.close();
}

int main() {

  // generateCSV();

  // genCSVForInt(7);
  leetTest();

  return 0;
}
