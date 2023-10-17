#include <bits/stdc++.h>
using namespace std;



int Pins, Colors, Guessed;
struct Query {
  int guess[105];
  int count[105];
  int hit, match;
} query[105];

int solution[105];

bool solve(int p) {
  for (int i = 0; i < Guessed; i++) {
    if (query[i].hit < 0 || query[i].hit > Pins - p || query[i].match < 0 ||
        query[i].match > Pins - p) {
      return false;
    }

  }
  if (p==Pins){
    return true;
  }
  for(int i=0; i <Colors; i++){
    solution[p] =i;
    for(int j=0; j<Guessed;j++){
        if(query[j].guess[p] == i){
            --query[j].hit;
        }
        if(query[j].count[i]-- >0){
            --query[j].match;
        }
    }
    if(solve(p+1)){
        return true;
    }
    for(int j=0; j<Guessed; j++){
        if(query[j].guess[p] == i){
            ++query[j].hit;
        }
        if(++query[j].count[i] >0){
            ++query[j].match;
        }
    }
  }
  return false;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        memset(query, 0, sizeof(query));
        cin >> Pins >> Colors >> Guessed;
        for(int m=0; m< Guessed; m++){
            for(int p=0; p<Pins; p++){
                int g;
                cin >> g;
                query[m].guess[p] = g-1;
                ++query[m].count[g-1];
            }
            cin >> query[m].hit >> query[m].match;
            query[m].match += query[m].hit;
        }
        if(solve(0)){
            for(int p=0; p<Pins ; p++){
                if(p>0){
                    cout  << " ";
                }
                cout << solution[p]+1;
            }
            cout << '\n';
        }else{
            cout << "You are cheating!" << '\n';
        }
    }

    return 0;
}