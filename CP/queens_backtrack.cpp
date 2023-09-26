#include <bits/stdc++.h>
using namespace std;

bool isSafe(int**, int, int, int);
bool solveNQueens(int**, int , int);

int main(){
    int n= 4;
    int** arr = new int*[n];
    for(int i=0; i<n;i++){
        arr[i] = new int[n];
    }
    // init
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            arr[i][j] = 0;
        }
    }
    bool isSolved = solveNQueens(arr, 0, n);

    if(isSolved){
        for (int i=0; i<n; i++ ){
            for (int j=0; j<n; j++ ){
                
            }
        }
    }

    return 0
}