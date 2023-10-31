#include <bits/stdc++.h>
using namespace std;

long long reverseNum(long long n){
    long long newN =0;
    while(n>0){
        newN = newN*10 + (n%10);
        n /=10;
    }
    return newN;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        long long a,b,c;
        cin>>a>>b;
        a = reverseNum(a);
        b = reverseNum(b);
        c=a+b;
        c= reverseNum(c);
        cout <<c<<'\n';
    }
}