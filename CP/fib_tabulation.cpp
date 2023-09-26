#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fib(int k){
    ll a=0, b=1;
    int x=1;
    ll temp;
    while(x<=k){
        temp = b;
        b = a+b;
        a = temp;
        x++;
    }
    return a;
}

int main(){
    int n;
    cin >> n;

    cout << fib(n) << '\n';
}