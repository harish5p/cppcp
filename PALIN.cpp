#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool isPali(int n) {
  string numStr = to_string(n);
  string reversedStr = numStr;
  reverse(reversedStr.begin(), reversedStr.end());

  int reversedNum = stoi(reversedStr);
  if (reversedNum == n) {
    return 1;
  } else {
    return 0;
  }
}

void next_palindrome(int n) {

  while (!isPali(++n)) {
  }
  cout << n << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int t;
  cin >> t;
  if (t > 0) {
    vector<int> arr(t);
    for (int i = 0; i < t; i++) {
      cin >> arr[i];
    }

    for (int j = 0; j < arr.size(); j++) {
      next_palindrome(arr[j]);
    }
  }

  return 0;
}