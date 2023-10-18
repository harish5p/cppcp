#include <bits/stdc++.h>
using namespace std;

int input(){
    int x=0;
    char c;
    for(;;){
        c = getchar();
        if(c=='\n'){
            return x;
        }
        x=10*x+c-'0';
    }
}

int a,b,c;

void solve(int level){
    if(level>a){
        a=level;
        c=b;
    }
    char C=getchar();
    if(C=='0'){
        return;
    }else{
        b++;
        solve(level+1);
        solve(level+1);
    }

}

int main(){
    int i,n;
    for(i=0;i<10;i++){
        n=input();
        a=-1;
        b=0;
        solve(0);
        getchar();
        cout << c <<'\n';
    }
    return 0;
}