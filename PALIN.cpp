#include <bits/stdc++.h>
#include <cmath>
using namespace std;


// 56 57 58 59 60 61 62 63 64 65 66 
// 31 33
// 111 121
// 156 161
// 651 656

// even or odd
// even 
// 5678 compare first and last
// if last > first then increase last by  10*first - last
// 5685
// 68
// if last> first as long as it's 2 digit find next palindrome
//  234567
// 234572
// 3457
// 3463
// 46
// 55
// 235532
//  
// case 2: 765432
// if first > last , change last to first
//  765437
// 6543
// 6546
// 54
// 55

// case 3: 246813
// 246822
// 4682
// 4684
// 2477742




bool isPali(int n) {

  string numStr = to_string(n);
  if (equal(numStr.begin(), numStr.begin() + numStr.size() / 2,
            numStr.rbegin())) {
    return 1;
  } else {
    return 0;
  }

  //   string reversedStr = numStr;
  //   reverse(reversedStr.begin(), reversedStr.end());

  //   int reversedNum = stoi(reversedStr);
  //   if (reversedNum == n) {
  //     return 1;
  //   } else {
  //     return 0;
  //   }
}

void next_palindrome(int n) {
  n++;

  while (!isPali(n)) {
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