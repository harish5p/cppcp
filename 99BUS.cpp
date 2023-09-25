// https://www.youtube.com/watch?v=Gc4mWrmJBsw - Floyd Warshall Algorithm

#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  const int MAX_LINES = 51;
  const int MAX_STOPS = 51;
  const int NEVER = 999999;

  int n;                         // bus lines
  vector<int> line[MAX_LINES];   // stops for each line
  long long int news[MAX_LINES]; // news or meet for each line
  int pos[MAX_LINES];            // current pos of bus

  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      line[i].clear();
      news[i] = (1LL << i);
      pos[i] = 0;

      int numStops;
      cin >> numStops;
      for (int j = 0; j < numStops; j++) {
        int stop;
        cin >> stop;
        line[i].push_back(stop);
      }
    }
    int time = 0;
    int maxIterations = n * n + 1;
    int lastExchangeTime = 0;

    while (maxIterations > 0) {
      bool exchangeOccured = false;

      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (line[i][pos[i]] == line[j][pos[j]] && (news[i] ^ news[j])) {
            maxIterations = n * n + 1;
            news[i] |= news[j];
            news[j] |= news[i];
            exchangeOccured = true;
          }
        }
      }
      if (exchangeOccured) {
        lastExchangeTime = time;
      }
      for (int i = 0; i < n; i++) {
        pos[i] = (pos[i] + 1) % line[i].size();
      }
      maxIterations--;
      time++;
    }
    bool allDriversKnow = true;
    for (int i = 0; i < n; i++) {
      if (news[i] != ((1LL << n) - 1)) {
        allDriversKnow = false;
        break;
      }
    }

    if (allDriversKnow) {
      cout << lastExchangeTime << endl;
    } else {
      cout << "NEVER" << '\n';
    }
  }

  return 0;
}