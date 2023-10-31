// https://chat.openai.com/c/51278b44-4a1f-45bc-af61-ce328e3badc4

// dp[j][k] = dp[j-1][k-1] + dp[j-1][k+1] if must[j] = false
// dp[j][k] = dp[j-1][k-1] if must[j] = true

// https://neppramod.wordpress.com/2017/09/24/square-brackets-spoj/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int d;
    int i, n, k, j, x;
    bool must[38];
    int dp[38][39];
    cin >> d;
    for (i = 0; i < d; i++)
    {
        cin >> n >> k;
        memset(must, false, sizeof(must));
        for (j = 0; j < k; j++)
        {
            cin >> x;
            must[x - 1] = true;
        }

        // DP state: character | #opening-#closing
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        for (j = 1; j < 2 * n; j++)
        {
            // Add opening bracket
            for (k = 1; k <= 38; k++)
                dp[j][k] += dp[j - 1][k - 1];

            // Add closing bracket if possible
            if (!must[j])
                for (k = 0; k < 38; k++)
                    dp[j][k] += dp[j - 1][k + 1];

            // Print the DP table after each iteration
            cout << "DP table after iteration " << j << ":\n";
            for (int p = 0; p <= 2 * n; p++)
            {
                for (int q = 0; q <= 38; q++)
                {
                    cout << dp[p][q] << ' ';
                }
                cout << endl;
            }
            cout << endl;
        }
        cout << dp[2 * n - 1][0] << endl;
    }
    return 0;
}
