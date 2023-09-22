#include <bits/stdc++.h>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int get_priority(char oper) {
  unordered_map<char, int> priority;
  priority['+'] = 1;
  priority['-'] = 1;
  priority['*'] = 2;
  priority['/'] = 2;
  priority['^'] = 3;
  return priority[oper];
}

string infix_to_postfix(const string &expression) {
  stack<char> operators;
  string rpn;
  for (int i=0; i< expression.length(); i++) {
    char token = expression[i];
    if (isalpha(token)) {
      rpn += token;
    } else if (token == '(') {
      operators.push(token);
    } else if (token == ')') {
      while (!operators.empty() && operators.top() != '(') {
        rpn += operators.top();
        operators.pop();
      }
      operators.pop();
    } else {
      while (!operators.empty() &&
             (get_priority(operators.top()) >= get_priority((token)))) {
        rpn += operators.top();
        operators.pop();
      }
      operators.push(token);
    }
  }
  while (!operators.empty()) {
    rpn += operators.top();
    operators.pop();
  }
  return rpn;
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
    cout << infix_to_postfix(arr[i]) << "\n";
  }

  return 0;
};
