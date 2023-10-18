#include <bits/stdc++.h>
#include <string>
using namespace std;

int arr[] = {1, 20, 360, 7200, 144000, 2880000, 57600000};

int main() {
  int n, k, count;
  long long sum;

  cin >> n;
  cin.ignore();

  while (n != 0) {
    string str;
    k = n - 1;
    sum = 0;
    for (int i = 0; i < n; i++) {
      getline(cin, str);
      count = 0;
      for (int j = 0; j < str.length(); j++) {
        if (str[j] == '.') {
          count++;
        } else if (str[j] == '-') {
          count += 5;
        }
      }
      sum += count * arr[k];
      k--;
    }
    cout <<sum <<'\n';
    cin >>n;
    cin.ignore();
  }
}