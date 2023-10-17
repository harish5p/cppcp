#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int seq[MAX][MAX];

int main(){
    int N, given, asked, i,j;
    cin >>N;
    while(N--){
        cin >> given >> asked;
        for(i=0; i<given; i++){
            cin >> seq[0][1];
        }
        for(i=1; i<given;i++){
            for(j=0; j<given-i;j++){
                seq[i][j] = seq[i-1][j-1] - seq[i-1][j];
            }
        
        }
        for(i=1; i<= asked; i++){
            seq[given-1][i] = seq[given-1][i-1];
        }
        for(i=given -2;i>=0;i--){
            for (j= given-1; j<given-1+asked; j++){
                seq[i][j] = seq[i+1][j-1] + seq[i][j-1];
            }
        }
        cout << seq[0][given];
        for(i=1; i<asked; i++){
            cout << " " << seq[0][given+1];
        }
        cout << '\n';
    }
    return 0;
}