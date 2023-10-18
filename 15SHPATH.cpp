#include <bits/stdc++.h>
#include <utility>
using namespace std;

const int MAX = 10001;

vector<pair<int,int>> cities[MAX];
map<string, int> mp;
int dist[MAX];

void dj(int src, int end){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(int i=0; i<cities[u].size();i++){
            int v = cities[u][i].second;
            int c = cities[u][i].first;
            if(dist[u]+c<dist[v]){
                dist[v] = dist[u]+c;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

}

int main(){
    int N;
    cin >> N;
    int n,p,nr,cost,r;
    while(N--){
        cin >> n;
        char str[20];
        for(int i=0; i<n;i++){
            scanf("%s%d",str,&p);
            mp[str] = i+1;
            for(int j=0; j<p;j++){
                cin >> nr >> cost;
                cities[nr].push_back(make_pair(cost, i+1));
            }
        }
        cin >> r;
        char s1[20],s2[20];
        for(int i=0; i<r; i++){
            scanf("%s%s",s1,s2);
            int u = mp[s1];
            int v = mp[s2];

            for(int j=0; j<=n; j++){
                dist[j] = 1e9;
            }
            dj(u,v);
            cout << dist[v] << '\n';
        }
        for(int i=0; i<=n;i++){
            cities[i].clear();
        
        }
        mp.clear();

    }
    return 0;
}