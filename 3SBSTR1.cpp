// KMP algo explanation -> https://www.youtube.com/watch?v=JoF0Z7nVSrA
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

vector<int> get_lps(const string& sub){
    int sublen = sub.length();
    vector<int> lps(sublen, 0);
    int len = 0;

    for(int i=1; i< sublen;){
        if (sub[i] == sub[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0){
                len = lps[len -1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(const string& main, const string& sub){
    vector<int> result;
    int mainlen = main.length();
    int sublen = sub.length();

    vector<int> lps = get_lps(sub);

    int i= 0, j=0;
    while(i<mainlen){
        if (sub[j] == main[i]){
            i++;
            j++;
        }
        if (j == sublen){
            result.push_back(i-j);
            j = lps[j-1];
        } else if (i < mainlen && sub[j] != main[i]){
            if (j !=0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    return result;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  
  string arr[48];

  for (int i = 0; i < 48; i+=2) {
    cin >> arr[i] >> arr[i+1];
  }
  for (int i = 0; i < 48; i+=2) {
    string main = arr[i];
    string sub = arr[i+1];
    
    vector<int> occurences = kmp(main, sub);
    if (occurences.empty()){
        cout << "0" << '\n';
    } else{
        cout << "1" << '\n';
    }
  }

  return 0;
}