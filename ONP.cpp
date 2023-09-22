#include <bits/stdc++.h>
#include <stack>
using namespace std;

int precedence(char c) {
  if (c == '+') {
    return 0;
  } else if (c == '-') {
    return 1;
  } else if (c == '*') {
    return 2;
  } else if (c == '/') {
    return 3;
  } else {
    return 4;
  }
}

bool isOper(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return 1;
    }
    return 0;
}

void transform(string s) {
    int i=0,j=0;

    while (s[i] !='\0'){

    }
}

int main() {
  int t;
  string arr[t];
  for (int i = 0; i < t; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < t; i++) {
    transform(arr[i]);
  }

  return 0;
}