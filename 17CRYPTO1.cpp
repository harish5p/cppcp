#include <ctime>
#include <bits/stdc++.h>
using namespace std;

const unsigned MOD = 4000000007;

unsigned modul(unsigned base, int exponent){
    int mask =1;
    unsigned long long result =1;
    unsigned long long p = base;
    while(exponent){
        if(exponent & mask){
            result = (result *p)% MOD;
            exponent &= ~mask;
        }
        p = (p*p) %MOD;
        mask <<=1;
    }
    return result;
}

int main(){
    unsigned a;
    cin >> a;
    auto x = modul(a, (MOD+1)/4);
    time_t t = x > MOD/2 ? MOD-x:x;
    char result[27] = {};
    strftime(result, 27, "%c", gmtime(&t));
    cout << result << '\n';

}
