#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solveGrid(int x, int y){
    ll arr[x+1][y+1];
    for (int i=0; i<=x; i++){
        for (int j=0; j <=y; j++){
            arr[i][j] = 0;
        }
    }
    arr[1][1]=1;
    for (int i=0; i<=x; i++){
        for (int j=0; j<=y; j++){
            if (i !=x){
                arr[i+1][j] += arr[i][j];
            }
            if (j !=y){
                arr[i][j+1] += arr[i][j];
            }
        }
    }
    return arr[x][y];
}

int main(){
    int x,y;
    cin >> x >> y;

    cout << solveGrid(x,y) << '\n';
}