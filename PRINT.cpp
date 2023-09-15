#include <bits/stdc++.h>
#include <cmath>
#include <ratio>
#include <vector>

using namespace std;

// bool isPrime(int);

vector<int> primes() {
  vector<int> vec;
  for (int i = 2; i <= INT_MAX; i++) {

    if (i == 2) {
      vec.push_back(2);
    } else if (i == 3) {
      vec.push_back(3);
    } else {
      for (int j = 0; j < vec.size(); j++) {
        if (i % vec.at(j) == 0) {
          break;
        }
      }
      vec.push_back(i);
      // cout <<vec.size() << endl;
      // break;
      
    }
  }
  return vec;
}

// bool isPrime(int number) {
//   if (number == 1) {
//     return 0;
//   } else if (number == 2) {
//     return 1;

//   } else if (number == 3) {
//     return 1;
//   } else {
//     for (int i = 2; i <= sqrt(number); i++)
//       if (number % i == 0) {
//         return 0;
//       }
//   }
//   return 1;
// }

// bool isEven(int num) { return (!(num & 1)); }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  unsigned short int t;
  cin >> t;

  //   int arr[300];
  vector<pair<int, int>> ranges(t);

  vector<int> vec = primes();

  for (int i = 0; i < t; i++) {

    cin >> ranges[i].first >> ranges[i].second;
  }

  for (int j = 0; j < t; j++) {

    for (int m = ranges[j].first; m <= ranges[j].second; m++) {
      if (m == 2) {
        cout << 2 << "\n";
      } else if (m == 3) {
        cout << 3 << "\n";
      } else {
        for (int k = 0; k <= vec.size(); k++) {
          if (k <= m) {

            if (k % vec.at(j) == 0) {
              break;
            }

          } else {
            break;
          }
        }
        cout << m << "\n";
      }

      // if (m == 2) {
      //   cout << m << endl;
      // } else if (isEven(m)) {

      // } else if (isPrime(m)) {
      //   cout << m << "\n";
      // }
    }
    // cout << "\n";
  }
  return 0;
}


// int main() {
//   std::ios_base::sync_with_stdio(false);
//   std::cin.tie(NULL);
  


//   unsigned short int t;
//   cin >> t;

//   int arr[300];


//   for (int i = 0; i < t; i++) {

//     cin >> arr[2 * i] >> arr[2 * i + 1];
//   }

//   vector<int> vec = primes();

//   for (int j = 0; j < t; j++) {

//     for (int m = arr[2 * j]; m <= arr[2 * j + 1]; m++) {
//       if (m == 2) {
//         cout << 2 << "\n";
//       } else if (m == 3) {
//         cout << 3 << "\n";
//       } else {
//         for (int k = 0; k <= vec.size(); k++) {
//           if (k <= m) {

//             if (k % vec.at(j) == 0) {
//               break;
//             }

//           } else {
//             break;
//           }
//         }
//         cout << m << "\n";
//       }

      
//     }
    
//   }
//   return 0;
// }
