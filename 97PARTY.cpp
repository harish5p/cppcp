#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int best, budget, n, cost, fun, i, j;
  while (cin >> budget >> n) {
    if (!budget && !n) {
      break;
    }

    vector<vector<int>> dp(n + 1, vector<int>(budget + 1, 0));

    for (i = 1; i <= n; i++) {
      cin >> cost >> fun;
      for (j = 1; j <= budget; j++) {
        if (j < cost) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + fun);
        }
      }
    }
    
    j = budget;
    while(dp[n][j] == dp[n][budget]){
        j--;
    }
    cout << j + 1 << " " <<dp[n][budget] << '\n';
  }
  return 0;
}