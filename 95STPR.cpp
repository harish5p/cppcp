#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N !=0){
        int cur, req = 1;
        stack<int> stk;
        for(int i=0; i<N;i++){
            cin >> cur;
            if(cur==req){
                req++;
            }else{
                stk.push(cur);
            }
            while(!stk.empty() && stk.top() == req){
                stk.pop();
                req++;
            }

        }
        while(!stk.empty()){
            if(stk.top() == req){
                stk.pop();
                req++;
            }else{
                break;
            }
        }
        if(stk.empty()){
            cout << "yes" << '\n';
        } else{
            cout << "no" <<'\n';
        }
        cin >> N;
    }
}

// https://chat.openai.com/c/d1b8527d-fbce-471e-b472-dce2cb53dab2