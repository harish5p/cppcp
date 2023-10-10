#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
  stack<int> st;
  string res = "";
  int i = a.length() - 1;
  int j = b.length() - 1;
  int carry = 0;
  int sum;
  while (i >= 0 && j >= 0) {
    sum = (a[i] - 48) + (b[j] - 48) + carry;
    st.push(sum % 10);
    carry = sum / 10;
    i--;
    j--;
  }
  while (i >= 0) {
    sum = (a[i] - 48) + carry;
    st.push(sum % 10);
    carry = sum / 10;
    i--;
  }
  while (j >= 0) {
    sum = (b[j] - 48) + carry;
    st.push(sum % 10);
    carry = sum / 10;
    j--;
  }
  while (carry) {
    st.push(carry % 10);
    carry /= 10;
  }
  while (!st.empty()) {
    res.append(1, st.top() + 48);
    st.pop();
  }
  return res;
}

string onlynumbers(string s) {
  string res = "";
  int i;
  // Iterate through the input string 's' until a non-zero character is found
  for (i = 0; i < s.length() && s[i] == '0'; i++)
    ;
  while (i < s.length()) {
    res.append(1, s[i]);
    i++;
  }
  if (res == "") {
    res = "0";
  }
  return res;
}

string sub(string a, string b) {
  stack<int> st;
  string res = "";
  int i = a.length() - 1;
  int j = b.length() - 1;
  while (i >= 0 && j >= 0) {
    if (a[i] >= b[j]) {
      st.push(a[i] - b[j]);
    } else {
      int k = i - 1;
      while (k >= 0 && a[k] == '0') {
        a[k] = '9';
        k--;
      }
      a[k]--;
      st.push(10 + a[i] - b[j]);
    }
    i--;
    j--;
  }
  while (i >= 0) {
    st.push(a[i] - 48);
    i--;
  }
  while (!st.empty()) {
    res.append(1, st.top() + 48);
    st.pop();
  }
  return onlynumbers(res);
}

vector<string> splitstr(string s) {
  string x = "";
  string y = "";
  int i;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '*' || s[i] == '+' || s[i] == '-') {
      break;
    }
    x.append(1, s[i]);
  }
  string oper;
  oper.append(1, s[i]);
  for (int j = i + 1; j < s.length(); j++) {
    y.append(1, s[j]);
  }
  vector<string> res;
  res.push_back(x);
  res.push_back(oper);
  res.push_back(y);

  return res;
}

void print(vector<string> s, string res) {
  int max_length = max(res.length(), max(s[0].length(), s[2].length() + 1));

  string first, second, result, dashes;
  first.append(max_length - s[0].length(), ' ');
  first.append(s[0]);

  second.append(max_length - s[2].length() - 1, ' ');
  second.append(s[1]);
  second.append(s[2]);

  dashes.append(max_length - max(s[2].length() + 1, res.length()), ' ');
  dashes.append(max(s[2].length() + 1, res.length()), '-');

  result.append(max_length - res.length(), ' ');
  result.append(res);

  // Use cout for output
  cout << first << endl;
  cout << second << endl;
  cout << dashes << endl;
  cout << result << endl;
}

string intMultiply(string a, int b) {
  stack<int> st;
  string res = "";
  int i = a.length() - 1, carry = 0, sum;
  while (i >= 0) {
    sum = (b * (a[i] - 48)) + carry;
    carry = sum / 10;
    st.push(sum % 10);
    i--;
  }
  while (carry) {
    st.push(carry % 10);
    carry /= 10;
  }
  while (!st.empty()) {
    res.append(1, st.top() + 48);
    st.pop();
  }
  return res;
}

vector<string> multiply(string s, string t) {
  vector<string> product;
  int power = 0;
  string res = "0", tmp = "", dispTmp = "";
  stack<int> st;
  for (int i = t.length() - 1; i >= 0; i--) {
    tmp = intMultiply(s, t[i] - 48);
    tmp = onlynumbers(tmp);
    dispTmp = tmp;
    tmp.append(power, '0');
    dispTmp.append(power, ' ');
    product.push_back(dispTmp);
    power++;

    res = add(res, tmp);
  }
  product.push_back(res);
  return product;
}

void display(vector<string> s, vector<string> result) {
  int maxLength = max(s[0].length(), s[2].length() + 1);
  for (int i = 0; i < result.size(); i++)
    maxLength = max((int)result[i].length(), maxLength);
  string tmp, first, second, dashes1, dashes;
  first.append(maxLength - s[0].length(), ' ');
  first.append(s[0]);
  cout << first << '\n';
  second.append(maxLength - s[2].length() - 1, ' ');
  second.append(s[1]);
  second.append(s[2]);
  cout << second << '\n';
  dashes1.append(maxLength - max(result[0].length(), s[2].length() + 1), ' ');
  dashes1.append(max(result[0].length(), s[2].length() + 1), '-');
  cout << dashes1 << '\n';
  int i;
  for (i = 0; i < result.size() - 1; i++) {
    tmp = "";
    tmp.append(maxLength - result[i].length(), ' ');
    tmp.append(result[i]);
    cout << tmp << '\n';
  }
  if (result.size() != 2) {
    dashes.append(
        maxLength - max(result[i].length(), result[result.size() - 1].length()),
        ' ');
    dashes.append(max(result[i].length(), result[result.size() - 1].length()),
                  '-');
    cout << dashes << '\n';
    tmp = "";
    tmp.append(maxLength - result[result.size() - 1].length(), ' ');
    tmp.append(result[result.size() - 1]);
    cout << tmp << endl;
  }
}

int main() {

  string s;
  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    vector<string> split = splitstr(s);
    if (split[1] == "*") {
      if (split[0] == "0" || split[2] == "0")
        print(split, "0");
      else
        display(split, multiply(split[0], split[2]));
    } else if (split[1] == "+")
      print(split, add(split[0], split[2]));
    else
      print(split, sub(split[0], split[2]));
    printf("\n");
  }
  return 0;
}