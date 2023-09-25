// https://chat.openai.com/c/ed1d1eba-a623-4f2b-8400-10defeb3ef86 - explanation
// we are first making the top row as 1s and loop over each row and check if it and the above row is 0, then toggle them to 1, otherwise no change.
// we are first checking to make each row as 1s using bottom row
// any lateral changes are fixed when we are checking the second condition

#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

const int MAX_ROWS = 15;
const int MAX_COLS = 15;

int rows, cols;
bool on[MAX_ROWS][MAX_COLS];
bool backup[MAX_ROWS][MAX_COLS];

void dance(int i, int j) {
  int di[] = {+0, +0, +1, -1};
  int dj[] = {+1, -1, +0, +0};
  on[i][j] = !on[i][j];
  for (int k = 0; k < 4; k++) {
    if (0 <= (i + di[k]) && (i + di[k]) < rows && 0 <= (j + dj[k]) &&
        (j + dj[k]) < cols) {
      on[i + di[k]][j + dj[k]] = !on[i + di[k]][j + dj[k]];
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  while (cin >> cols >> rows && rows && cols) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        char c;
        cin >> c;
        on[i][j] = (c == '1');
      }
    }
    memcpy(backup, on, sizeof on);
    bool solved = false;
    vector<pair<int, int>> ans(rows * cols + 1);

    for (int set = 0; set < (1 << cols); set++) {
      memcpy(on, backup, sizeof on);
      vector<pair<int, int>> path;
      for (int j = 0; j < cols; j++) {
        if (set & (1 << j)) {
          dance(0, j);
          path.push_back(make_pair(0, j));
        }
      }
      for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          if (!on[i - 1][j]) {
            dance(i, j);
            path.push_back(make_pair(i, j));
          }
        }
      }
      bool ok = true;
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          ok &= on[i][j];
        }
      }
      if (ok && path.size() < ans.size()) {
        ans = path;
        solved = true;
      }
    }
    if (!solved) {
      cout << -1 << '\n';
    } else {
      cout << ans.size() << '\n';
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;
      }
    }
  }

  return 0;
}