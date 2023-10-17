#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int num, res=0;
        cin >> num;

        while(num>0){
            num /= 5;
            res += num;
        }
        cout << res << '\n';
    }


    return 0;
}