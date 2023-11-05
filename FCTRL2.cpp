#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &num, int a){
    int carry=0;
    for(int i=0; i<num.size(); i++){
        num[i] = num[i]*a +carry;
        carry = num[i]/10;
        num[i] = num[i]%10;
    }
    while(carry){
        num.push_back(carry%10);
        carry/=10;
    }
}
void factorial(int n){
    vector<int> fact;
    fact.push_back(1);
    for(int i=2; i<=n; i++){
        multiply(fact,i);
    }
    for(int i=fact.size()-1; i>=0;i--){
        cout << fact[i];
    }
    cout <<'\n';
}
int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        factorial(n);
    }
}