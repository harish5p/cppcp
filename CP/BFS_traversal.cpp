#include <bits/stdc++.h>
#include <typeindex>
using namespace std;

class Graph {
public:
  map<int, bool> visited;
  map<int, vector<int>> adj_list;

  auto addEdge(int s, int d) { adj_list[s].push_back(d); }

  auto bfsPrint(int v) {
    visited.clear();
    list<int> queue;
    visited[v] = true;
    queue.push_back(v);
    while (!queue.empty()) {
      v = queue.front();
      cout << v << " ";
      queue.pop_front();

      for (auto it = adj_list[v].begin(); it != adj_list[v].end(); it++) {
        if (visited[*it] != true) {
          visited[*it] = true;
          queue.push_back(*it);
        }
      }
    }
    visited.clear();
  }
};

int main() {
  Graph g;
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.bfsPrint(2);
}

