#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fib(int x, vector<ll>& dp){
    if (x==0){
        dp[x] = 0;
        return 0;
    }
    if (x==1){
        dp[x] = 1;
        return 1;
    }
    ll a,b;
    if (dp[x-2] != -1){
        a = dp[x-2];
    } else {
        a = fib(x-2, dp);
    }

    if (dp[x-1] != -1){
        b = dp[x-1];
    } else {
        b = fib(x-1, dp);
    }
    dp[x] = a+b;
    return (a+b);

}

int main(){
    int n;
    cin >> n;
    vector <ll> dp;
    dp.resize(n+1);
    for (int i=0; i< dp.size(); i++){
        dp[i] = -1;
    }
    cout << fib(n,dp) << '\n';

    for (int i=0; i<dp.size(); i++){
        cout << i<< " "<< dp[i] << '\n';
    }
}