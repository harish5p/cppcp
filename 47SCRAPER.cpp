#include <bits/stdc++.h>

using namespace std;

// https://math.stackexchange.com/questions/3325185/find-all-the-integral-solutions-to-the-equation-323x391y437z-10473/3327153#3327153
// https://math.stackexchange.com/questions/4069402/solve-trivariate-linear-diophantine-equation-2x-3y-4z-5
// https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
// https://math.stackexchange.com/questions/67969/linear-diophantine-equation-100x-23y-19/68021#68021
int euclid(int a, int b, int &x, int &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int x2, y2;
  int result = euclid(b % a, a, x2, y2);
  y = x2;
  x = y2 - (b / a) * x2;
  return result;
}

bool solve(int a, int b, int m, int &x) {
  int y, z;
  int d = euclid(abs(a), m, y, z);
  if (a < 0) {
    y *= -1;
  }
  if (b % d) {
    return false;
  }
  long long xx = y;
  xx *= b / d;

  x = ((xx % (m / d)) + m / d) % (m / d);

  return true;
}

bool transferable(int X1, int Y1, int X2, int Y2, int F){
    if (Y1<Y2){
        return transferable(X2, Y2, X1, Y1,  F);
    }
    int x;
    if(!solve(X1, Y2-Y1, X2, x)){
        return false;
    }
    return Y1+x*X1 <F;
}

bool input(){
    int F,E,A,B;
    cin >>F>>E>>A>>B;
    vector<int> X(E), Y(E);
    vector<int> target(E);
    stack<int> stk;
    for(int i=0; i<E; i++){
        cin >> X[i] >>Y[i];
        if(Y[i] <=B && (B-Y[i])%X[i]==0){
            target[i] = 1;
        }
        if(Y[i]<= A && (A-Y[i])%X[i] == 0){
            stk.push(i);
        }
    }
    if(A==B){
        return true;
    }
    vector<int> vis(E,0);
    while(!stk.empty()){
        int i = stk.top();
        stk.pop();
        if(vis[i]){
            continue;
        }
        vis[i] = 1;
        if(target[i]){
            return true;
        }
        for(int j=0; j<E; j++){
            if (j==i ||vis[j]){
                continue;
            } 
            if (transferable(X[i], Y[i],X[j], Y[j], F)){
                stk.push(j);
            }
        }
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        if(input()){
             cout << "It is possible to move the furniture.\n";
        }else{
            cout << "The furniture cannot be moved.\n";
        }
    }
}