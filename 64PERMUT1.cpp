#include <bits/stdc++.h>
using namespace std;

int inv[100];

void findInv(int l, int e){
    if(l>e){
        return ;

    }
    int temp[100];
    memset(temp, 0, sizeof(temp));
    for(int i=0; i<l;i++){
        for(int k=i;k<100;k++){
            temp[k] += inv[k-i];
        }
    }
    for(int i=0;i<100;i++ ){
        inv[i] = temp[i];
    }
    findInv(l+1,e);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin >>n>>k;
        if(n==1){
            cout << (k==0?1:0) <<'\n';
            continue;
        }
        memset(inv, 0,sizeof(inv));
        inv[0] = inv[1] = 1;
        findInv(3,n);
        cout << inv[k] <<'\n';
    }
}