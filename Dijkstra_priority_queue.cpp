#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;

const int INF = 99999;

void addEdge(vector<pair<int, int>> graph[], int u, int v, int w) {
  graph[u].push_back({v, w});
  graph[v].push_back({u, w});
}

void dj(vector<pair<int, int>> graph[], int src, int V) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(V, INF);
  pq.push(make_pair(0, src));
  dist[src] = 0;

  // BFS traversal
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (auto x : graph[u]) {
      int v = x.first;
      int wt = x.second;
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
  cout << "Vertex Distance from src \n";
  for (int i = 0; i < V; i++) {
    cout << i << '\t' << dist[i] << '\n';
  }
}

int main() {
  int V = 9;
  vector<pair<int, int>> graph[V];
  addEdge(graph, 0, 1, 4);
  addEdge(graph, 0, 7, 8);
  addEdge(graph, 1, 2, 8);
  addEdge(graph, 1, 7, 11);
  addEdge(graph, 2, 3, 7);
  addEdge(graph, 2, 8, 2);
  addEdge(graph, 2, 5, 4);
  addEdge(graph, 3, 4, 9);
  addEdge(graph, 3, 5, 14);
  addEdge(graph, 4, 5, 10);
  addEdge(graph, 5, 6, 2);
  addEdge(graph, 6, 7, 1);
  addEdge(graph, 6, 8, 6);
  addEdge(graph, 7, 8, 7);

  dj(graph, 0, 9);
}