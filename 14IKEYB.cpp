// https://chat.openai.com/c/df6f8958-7c70-4713-89d2-eef2a3463c7b
//  dp and backtrackings

#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;
  for (int x = 1; x <= N; x++) {
    cout << "Keypad #" << x << ":\n";
    int K, L;
    cin >> K >> L;

    string keys, letters;
    cin >> keys >> letters;
    vector<int> frequency(L);
    for (int i = 0; i < L; i++) {
      cin >> frequency[i];
    }
    struct item {
      int price = 0;
      int i_prev = 0;
    };
    vector<vector<item>> dp(L + 1, vector<item>(K + 1));
    for (int i = 1; i <= L; i++) {
      // cout << "i is: " << i <<'\n';
      dp[i][0].price = 1e9;
      for (int j = 1; j <= K; j++) {
        // cout << "j is: " << j <<'\n';
        dp[i][j] = {dp[i][j - 1].price, i};
        int frequency_sum = 0;
        int key_cost = 0;
        for (int m = 1; m <= i; m++) {
            cout << "i is: " << i<<'\n';
            cout << "j is: " << j <<'\n';
            cout << "m is: " << m <<'\n';
          cout << "frequency[i - m] is: " << frequency[i - m] <<'\n';
          frequency_sum += frequency[i - m];
          cout << "frequency_sum is: " << frequency_sum <<'\n';
          key_cost += frequency_sum;
                    cout << "key_cost is: " << key_cost <<'\n';
          const auto p = dp[i - m][j - 1].price + key_cost;
          cout << "p is: " << p <<'\n';
          if (p <= dp[i][j].price) {
            dp[i][j].price = p;
            dp[i][j].i_prev = i - m;
          }
        }
      }
      // Print the dp table after each iteration of i and j
            cout << "After iteration i=" << i << " and j=" << K << ":\n";
            for (int a = 1; a <= L; a++) {
                for (int b = 1; b <= K; b++) {
                    cout << "dp[" << a << "][" << b << "].price = " << dp[a][b].price << " ";
                }
                cout << endl;
            }
    }
    vector<int> letters_per_key(K);
    int i = L;
    for (int j = K; j > 0; j--) {
      letters_per_key[j - 1] = i - dp[i][j].i_prev;
      i = dp[i][j].i_prev;
    }
    int j = 0;
    for (int i = 0; i < K; i++) {
      cout << keys[i] << ": ";
      while (letters_per_key[i]--) {
        cout << letters[j];
        ++j;
      }
      cout << '\n';
    }
    cout << '\n';
  }

  return 0;
}