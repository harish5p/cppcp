#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

long long dj( vector<vector<pair<int, int>>> adj) {
  const int V = adj.size();
  vector<int> dist(V, 1e9 + 1);
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    int dis = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (dist[node] < -dis)
      continue;
    dist[node] = -dis;
    for (auto x : adj[node]) {
      int edgeWeight = x.second;
      int adjNode = x.first;
      pq.emplace(dis - edgeWeight, adjNode);
    }
  }
  return accumulate(dist.begin(), dist.end(), 0LL);
}



int main() {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;

  while (N--) {
    int V, E; cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);
    vector<vector<pair<int, int>>> radj(V);
    while (E--) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        radj[v].emplace_back(u, w);
    }
    cout << dj(adj) + dj(radj) << '\n';
  }
}