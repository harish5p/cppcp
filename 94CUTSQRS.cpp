#include <bits/stdc++.h>
#include <cstddef>
#include <math.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int a,b;
        cin >>a>>b;
        if (a==b){
            cout <<"7\n";
            continue;
        }
        vector<int> q;
        int sum =0;
        while(a){
            sum +=(b/a)-1;
            q.push_back(b/a);
            b %= a;
            swap(a,b);
        }
        const int l1 = 1 + floor(log10l(2)*sum);
        const int l2 = 1 + floor(log10l(2)*(sum-1));
        int i =0;
        while(i<q.size() && q[i]==1){
            ++i;
        }
        const int l3 = (i %2 == 0 ?5 : 6);
        cout << l1 + l2 + l3 << '\n';
    }
}