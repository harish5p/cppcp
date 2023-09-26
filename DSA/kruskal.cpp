// Union Find intution -> https://www.youtube.com/watch?v=JZBQLXgSGfs
// watch the entire playlist for more
// https://www.youtube.com/watch?v=0jNmHPfA_yE
// Path compression - https://www.youtube.com/watch?v=VHRhJWacxis
#include <iostream>

#define I 32767
#define V 7
#define E 9

using namespace std;

void printset(int set[], int n){
    for (int i=0; i<n;i++){
        cout << set[i] << " ";
    }
    cout << '\n';
}

void PrintMCST(int T[][V - 1], int A[][E]) {
  cout << "\nMinimum Cost Spanning Tree Edges\n" << '\n';
  for (int i = 0; i < V - 1; i++) {
    cout << '[' << T[0][i] << "] ---[" << T[1][i] << ']' << '\n';
  }
  cout << '\n';
}

void Union(int u, int v, int s[]) {
    cout << u << v <<'\n';

  if (s[u] < s[v]) {
    cout << "s[u] < s[v] and s[u]: " << s[u] << " s[v]: " << s[v] << '\n';
    s[u] += s[v];
    cout << "s[u] after adding s[v]" << s[u] << '\n';
    s[v] = u;
    cout << "s[v]: " << s[v] << '\n';
    cout << '\n';
    cout << '\n';
  } else {
    cout << "s[u] >= s[v] and s[u]: " << s[u] << " s[v]: " << s[v] << '\n';
    s[v] += s[u];
    cout << "s[v]: " << s[v] << '\n';
    s[u] = v;
    cout << "s[u]: " << s[u] << '\n';
    cout << '\n';
    cout << '\n';
  }
}

int Find(int u, int s[]) {
    
  int x = u;
  cout << "x: " << x <<'\n';
  int v = 0;
  while (s[x] > 0) {
    x = s[x];
    cout << "changed x to s[x]" << x << '\n';
  }
  while (u != x) { // connecting nodes with parent directly
    v = s[u];
    s[u] = x;
    u = v;
  }
  return x;
}

void KruskalMCST(int A[3][9]) {
  int T[2][V - 1];    // solution array
  int track[E] = {0}; // Track edges to include in solution
  int set[V + 1] = {-1, -1, -1, -1, -1, -1, -1, -1}; // Array for finding cycles

  int i = 0;
  while (i < V - 1) {
    int min = I;
    int u = 0;
    int v = 0;
    int k = 0;

    // Find a minimum cost edge from full graph
    for (int j = 0; j < E; j++) {
      if (track[j] == 0 && A[2][j] < min) {
        min = A[2][j];
        u = A[0][j];
        v = A[1][j];
        k = j;
      }
    }

    //  Check if the selected min cost edge (u,v) is forming a cycle
    if (Find(u, set) != Find(v, set)) {
        cout << u << '\n' << u <<'\n';
        cout << "Init set: ";
        printset(set, 8);
      T[0][i] = u;
      T[1][i] = v;

      // Perform Union
      Union(Find(u, set), Find(v, set), set);
      i++;
      cout << "after union";
      printset(set, 8);
    }
    track[k] = 1; // k edge is considered
  }
  PrintMCST(T, A);
}

int main() {
  int edges[3][9] = {
      {1, 1, 2, 2, 3, 4, 4, 5, 5}, // vertex 1
      {2, 6, 3, 7, 4, 5, 7, 6, 7}, // vertex 2
      {25, 5, 12, 10, 8, 16, 14, 20, 18}, // edge weight connecting vertex 1 and 2
  };
  KruskalMCST(edges);

  return 0;
}