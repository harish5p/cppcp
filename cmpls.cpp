#include <bits/stdc++.h>

using namespace std;

vector<int> difference(const vector<int> &A) {
  vector<int> B;
  for (int i = 0; i < A.size() - 1; i++) {
    B.push_back(A[i + 1] - A[i]);
  }
  return B;
}

// Function to check if all elements in the vector B are equal
bool check_equal(const vector<int> &B) {
  for (int i = 0; i < B.size() - 1; i++) {
    if (B[i] != B[i + 1]) {
      return false;
    }
  }
  return true;
}

auto diff_term(vector<int> diff, int j) {
  int n;
  int x = diff[j - 1] + (n - 1) * (diff[j]);
}

auto nth_term(int n, int no_to_print, vector<int> diff, vector<int> A) {
  int first_term = A[0] + (n - 1) * (diff[0]);
  int g = 1;
  int j;
  for (int i = j - 1; i > 0; i--) { // j is len of diff
    g *= diff[i - 1] + (n - 1) * (diff[i]);
  }
  int general_term = A[0] + (n - 1) * g;

  return general_term;
}

int gen_term(vector<int> diff, int x, int n) {
  int gen_term = 0;
  for (int i = 0; i <= x; i++) {
    int term = 1;
    for (int j = 0; j < i; j++) {
      term *= (n - j);
    }
    term *= diff[i];
    gen_term += term;
  }
  return gen_term;
}

int main() {

  int N;
  cin >> N;
  while (N--) {
    int S, C;
    cin >> S >> C;
    vector<int> diff(S);

    vector<int> A(S);
    for (int i = 0; i < S; i++) {
      cin >> A[i];
    }
    if (S != 1) {
      int j;
      for (j = 0; j < S; j++) {
        auto B = difference(A);
        diff[j] = B[0];
        cout << diff[j] << '\n';

        if (!check_equal(B)) {
          A = B;
        } else {
          break;
        }
      }
      cout << j << '\n';

    } else {
      // print number C times;
    }
  }

  return 0;
}