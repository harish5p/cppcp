#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool isPrime(int number) {
  if (number == 1) {
    return 0;
  } else if (number == 2) {
    return 1;

  } else if (number == 3) {
    return 1;
  } else {
    for (int i = 2; i <= sqrt(number); i++)
      if (number % i == 0) {
        return 0;
      }
  }
  return 1;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned short int t;
  cin >> t;

  int arr[20];

  for (int i = 0; i < t; i++) {

    cin >> arr[2 * i] >> arr[2 * i + 1];
  }

  for (int j = 0; j < t; j++) {

    for (int m = arr[2 * j]; m <= arr[2 * j + 1]; m++) {
      if (isPrime(m)) {
        cout << m << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}
