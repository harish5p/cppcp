#include <bits/stdc++.h>
using namespace std;

int solveGrid(int x, int y, vector<vector<int>> &dp) {
  cout << "Solving " << x << " " << y << '\n';
  if (x == 0 || y == 0) {
    dp[y][x] = 0;
    dp[x][y] = 0;

    return 0;
  }
  if (x == 1 || y == 1) {
    dp[x][y] = 1;
    dp[y][x] = 1;
    return 1;
  }
  int a;
  if (dp[x][y - 1] != -1) {
    a = dp[x][y - 1];
  } else if (dp[y - 1][x] != -1) {
    a = dp[y - 1][x];
  } else {
    a = solveGrid(x, y-1, dp);
    dp[x][y - 1] = a;
    dp[y - 1][x] = a;
  }
  int b;
  if (dp[x - 1][y] != -1) {
    b = dp[x - 1][y];
  } else if (dp[y][x - 1] != -1) {
    b = dp[y][x - 1];
  } else {
    b = solveGrid(x - 1, y, dp);
    dp[x - 1][y] = b;
    dp[y][x - 1] = b;
  }
  dp[x][y] = a + b;
  return (a + b);
}

int main() {
  int x, y;
  cin >> x >> y;

  vector<vector<int>> dp;
  dp.resize(x + 1);
  for (int i = 0; i < dp.size(); i++) {
    dp[i].resize(y + 1);
    for (int j = 0; j < dp[i].size(); j++) {
      dp[i][j] = -1;
    }
  }
  cout << solveGrid(x, y, dp) << '\n';

  return 0;
}