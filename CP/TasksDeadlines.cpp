#include <bits/stdc++.h>
using namespace std;

class Task{
    public:
    int duration, deadline;
    Task(){
        duration=0;
        deadline=0;
    }
};

bool compare(Task, Task);
int solveTasks(Task*, int);

int main(){
    int n;
    cout << "Enter total number of tasks" << '\n';
    cin >> n;
    Task* arr = new Task[n];
    cout << "Enter duration of all tasks respectively" << '\n';
    for (int i=0; i<n; i++){
        cin >> arr[i].duration;
    }
    cout << "Enter deadline of all tasks respectively" << '\n';
    for (int i=0; i<n; i++){
        cin >> arr[i].deadline;

    }
    cout << "You may view the tasks below" << '\n';
    cout << "Duration\tDeadline" << '\n';
    for (int i=0; i< n; i++){
        cout << arr[i].duration << '\t' << arr[i].deadline << '\n';

    }
    cout << "Maximum score possible is " << solveTasks(arr,n) << '\n';
    return 0;
}

bool compare(Task a, Task b){
    return (a.duration < b.duration);
}

int solveTasks(Task* arr, int n){
    sort(arr, arr+n, compare);
    int max_score = 0;
    int current_time = 0;

    for (int i=0; i<n; i++){
        current_time += arr[i].duration;
        max_score += arr[i].deadline -current_time;
    }
    return max_score;
}