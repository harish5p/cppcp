
#include <bits/stdc++.h>

#include <string>

using namespace std;

void print_math(string str) {
  int len = str.length();
  char oper;
  string first, second;
  for (int i = 0; i < len; i++) {
    if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
      first = str.substr(0, i);
      second = str.substr(i + 1, len - i - 1);
      oper = str[i];
    }
  }
  int first_len = first.length();
  int second_len = second.length();
  int dashes;

  if (oper == '+' || oper == '-') {
    if (first_len >= second_len + 1) {
      dashes = first_len;
      string dash_line(dashes, '-');
      string spaces(first_len - second_len - 1, ' ');
      cout << first << '\n';
      cout << spaces << oper << second << '\n';
      cout << dash_line << '\n';
    } else {
      dashes = second_len + 1;
      string dash_line(dashes, '-');
      string spaces(second_len + 1 - first_len, ' ');
      cout << spaces << first << '\n';
      cout << oper << second << '\n';
      cout << dash_line << '\n';
    }
  }

  if (oper == '+') {
    int result = stoi(first) + stoi(second);
    int result_len = to_string(result).length();

    if (result_len < dashes) {
      string result_spaces(dashes - (to_string(result).length()), ' ');
      cout << result_spaces << result << '\n';
    } else {
      cout << result << '\n';
    }
  }
  if (oper == '-') {
    int result = stoi(first) - stoi(second);
    int result_len = to_string(result).length();
    if (result_len < dashes) {
      string result_spaces(dashes - (to_string(result).length()), ' ');
      cout << result_spaces << result << '\n';
    } else {
      cout << result << '\n';
    }
  }

  if (oper == '*') {
    int result = stoi(first) * stoi(second);
    int result_len = to_string(result).length();

    string first_spaces(result_len - first_len, ' ');
    string second_spaces(result_len - second_len - 1, ' ');

    if (first_len >= second_len + 1) {
      dashes = first_len;
    } else {
      dashes = second_len + 1;
    }
    string dash_line(dashes, '-');
    string dash_spaces(result_len - dashes, ' ');

    cout << first_spaces << first << '\n';
    cout << second_spaces << oper << second << '\n';
    cout << dash_spaces << dash_line << '\n';

    int j = 0;
    for (int i = second_len - 1; i >= 0; i--) {
      int i_digit = stoi(string(1, second[i]));

      int inter_result = stoi(first) * i_digit;

      int inter_result_len = to_string(inter_result).length();
      string inter_spaces(result_len - inter_result_len - j, ' ');
      j++;
      cout << inter_spaces << inter_result << '\n';
    }

    string result_dashes(result_len, '-');

    cout << result_dashes << '\n';
    cout << result << '\n';
  }
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
    print_math(arr[i]);
    cout << '\n';
  }

  return 0;
}