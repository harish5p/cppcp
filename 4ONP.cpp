#include <bits/stdc++.h>
#include <vector>
using namespace std;

string to_postfix(string a) { 
    
    return a; 
    
    }

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;
  string arr[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    cout << to_postfix(arr[i]) << "\n";
  }

  return 0;
}
