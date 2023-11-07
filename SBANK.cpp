#include <bits/stdc++.h>

using namespace std;

int main(){
    int t,n;
    cin>>t;

    while(t--){
        cin >> n;
        cin.ignore();

        map<string, int> mp;
        string str;
        for(int i=0; i<n; i++){
            getline(cin,str);
            mp[str]++;
        }
        map<string,int>::iterator it = mp.begin();
        for(;it != mp.end(); it++){
            cout << (*it).first << " " << (*it).second << '\n';
        }
        if(t!=0){
            cout << '\n';
        }
    }
}