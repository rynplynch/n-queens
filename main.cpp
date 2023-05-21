#include "solveNQueens.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main() {

  std::cout << "Hello World" << std::endl;
  std::cout << "Hello World" << std::endl;

  ofstream aFile("filename.txt");

  aFile << "ITS WORKING!";
  aFile << "ITS WORKING!";

  vector<vector<string>> response;
  vector<vector<string>> checker;

  vector<string> answer0 = {".Q..", "...Q", "Q...", "..Q."};
  vector<string> answer1 = {"..Q.", "Q...", "...Q", ".Q.."};

  SolveNQueens solver = SolveNQueens();

  response = solver.solveNQueens(4);

  checker.push_back(answer0);
  checker.push_back(answer1);

  assert(response.size() == checker.size());
  assert(response[0] == checker[0]);
  assert(response[1] == checker[1]);
  aFile.close();
  // what is returned by this function
  return 0;
}
