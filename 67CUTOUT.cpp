#include <bits/stdc++.h>

using namespace std;

void ansv_left(vector<int> &v, vector<int> &res){
    stack<pair<int,int>> stk;
    stk.push(make_pair(INT_MIN, v.size()));
    for(int i = v.size()-1; i>=0;i--){
        while(stk.top().first>v[i]){
            res[stk.top().second] = i;
            stk.pop();
        }
        stk.push(make_pair(v[i],i));
    }
    while(stk.top().second <v.size()){
        res[stk.top().second] = -1;
        stk.pop();
    }
}

void ansv_right(vector<int> &v, vector<int> &res){
    stack<pair<int, int>> stk;
    stk.push(make_pair(INT_MIN, -1));
    for(int i=0; i<v.size(); i++){
        while(stk.top().first>v[i]){
            res[stk.top().second] = i;
            stk.pop();
        }
        stk.push(make_pair(v[i],i));
    }
    while(stk.top().second >-1){
        res[stk.top().second] = v.size();
        stk.pop();
    }
}

int main(){
    int d;
    cin>>d;
    while(d--){
        int n,r;
        cin >> n>>r;
        vector<int> xcords = {0,n};
        vector<int> ycords = {0,n};
        vector<int> x1(r), x2(r), y1(r), y2(r);
        for (int i=0; i<r; i++){
            cin >> x1[i] >> x2[i] >> y1[i] >> y2[i];
            xcords.push_back(x1[i]);
            xcords.push_back(x2[i]);
            ycords.push_back(y1[i]);
            ycords.push_back(y2[i]);
        }
        sort(xcords.begin(), xcords.end());
        sort(ycords.begin(), ycords.end());
        xcords.erase(unique(xcords.begin(), xcords.end()), xcords.end());
        ycords.erase(unique(ycords.begin(), ycords.end()), ycords.end());
        const auto x_to_cx = [&](int x){
            return lower_bound(xcords.begin(), xcords.end(),x) - xcords.begin();
        };
        const auto y_to_cy = [&](int y){
            return lower_bound(ycords.begin(), ycords.end(), y) - ycords.begin();
        };
        vector<vector<int>> darr(xcords.size(), vector<int>(ycords.size(), 0));
        for(int i=0; i<r; i++){
            const int cx1 = x_to_cx(x1[i]);
            const int cx2 = x_to_cx(x2[i]);
            const int cy1 = y_to_cy(y1[i]);
            const int cy2 =  y_to_cy(y2[i]);
            darr[cx1][cy1]++;
            darr[cx1][cy2]--;
            darr[cx2][cy1]--;
            darr[cx2][cy2]++;
        }
        vector<int> dcol(ycords.size()-1,0);
        for(int i=0; i<xcords.size()-1; i++){
            int psum=0;
            for(int j=0; j< darr[i].size()-1; j++){
                dcol[j] += darr[i][j];
                psum += dcol[j];
                darr[i][j]= psum;
            }
        }
        vector<int> empty_width(ycords.size()-1,0);
        int result =0;
        for(int i=0; i< xcords.size()-1; i++){
            for(int j=0; j<ycords.size()-1;j++){
                if(darr[i][j]){
                    empty_width[j]=0;
                }else{
                    empty_width[j] += xcords[i+1] - xcords[i];
                }
            }
            vector<int> al(ycords.size()-1);
            vector<int> ar(ycords.size()-1);
            ansv_left(empty_width, al);
            ansv_right(empty_width, ar);
            for(int j=0; j<ycords.size()-1;j++){
                int full_height = ycords[j+1] - ycords[j];
                full_height += ycords[j] - ycords[al[j]+1];
                full_height += ycords[ar[j]] - ycords[j+1];
                result = max(result, full_height*empty_width[j]);
            }
        }
        cout << result << '\n';
    }
}