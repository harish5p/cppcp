#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

int solveOptimal(int*, int);

int main(){
    int n;
    cout << "Enter total number of sorted files" << '\n';
    cin >> n;
    cout << "Enter size of all sorted files"<< '\n';
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    cout << "Minimum total computations required to merge these files is " << solveOptimal(arr, n) << '\n';
    return 0;
}

int solveOptimal(int* arr, int n){
    priority_queue<int, vector<int>, greater<int>> sorted_list;

    for (int i=0; i<n; i++){
        sorted_list.push(arr[i]);
    }
    int total_computations = 0;
    while(sorted_list.size() >1){
        int temp1 = sorted_list.top();
        sorted_list.pop();
        int temp2 = sorted_list.top();
        sorted_list.pop();
        total_computations += temp1 + temp2;

        sorted_list.push(temp1+temp2);

    }
    return total_computations;
}