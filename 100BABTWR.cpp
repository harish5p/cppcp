// https://www.youtube.com/watch?v=9mod_xRB-O0 - Box stacking algo
// https://www.youtube.com/watch?v=cjWnW0hdF1Y - LIS (Longest Increasing
// sequence)

#include <bits/stdc++.h>
#include <string>

using namespace std;

struct box {
  int l, b, h;
};

bool compare(box one, box two) { return one.l * one.b < two.l * two.b; }

int boxStacking(vector<box> boxes, int n) {

  vector<int> lis(3 * n);

  for (int i = 0; i < 3 * n; i++) {
    lis[i] = boxes[i].h;
  }

  for (int i = 1; i < 3 * n; i++) {
    for (int j = 0; j < i; j++) {
      if (boxes[j].l < boxes[i].l && boxes[j].b < boxes[i].b) {
        if (lis[j] + boxes[i].h > lis[i]) {
          lis[i] = lis[j] + boxes[i].h;
        }
      }
    }
  }
  int maxH = lis[0];
  for (int i = 1; i < 3 * n; i++) {
    if (lis[i] > maxH) {
      maxH = lis[i];
    }
  }
  return maxH;
}

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) {
      return 0;
    }
    int l, b, h;
    vector<box> boxes(3 * n);

    for (int i = 0; i < 3 * n; i++) {
      cin >> l >> b >> h;
      boxes[i].l = min(b, h);
      boxes[i].b = max(b, h);
      boxes[i].h = l;

      i++;
      boxes[i].l = min(l, h);
      boxes[i].b = max(l, h);
      boxes[i].h = b;

      i++;
      boxes[i].l = min(l, b);
      boxes[i].b = max(l, b);
      boxes[i].h = h;
    }
    sort(boxes.begin(), boxes.end(), compare);

    cout << boxStacking(boxes, n) << '\n';
  }
   

  return 0;
}
