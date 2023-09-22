// KMP algo explanation -> https://www.youtube.com/watch?v=JoF0Z7nVSrA
#include <bits/stdc++.h>

#include <string>
#include <vector>


using namespace std;

string next_palindrome(string str){
  int len = str.length();
  string dup = str;
  for (int i= len/2; i < len; i++){
    dup[i] = dup[len-i-1];
  }
  if (dup > str){
    return dup;
  } else{
    for (int i= (len-1)/2; i>=0; i--){
      if (str[i] != '9'){
        str[i]++;
        break;

      } else{
        str[i] = '0';
      }
    }
    for (int i= len/2; i <len; i++){
      str[i] = str[len-i-1];
    }
    if (str[0] == '0'){
      str+='1';
      str[0] = '1';
    }
    return str;
  }

}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  cin >> n;
  string arr[n];

  for (int i = 0; i < n; i ++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i ++) {
    cout << next_palindrome(arr[i]) << '\n';
  }

  return 0;
}