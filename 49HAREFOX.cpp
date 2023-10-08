#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (N--) {
    double a, b, c, d, h, f, hy, fy;
    double inih, inif;
    cin >> a >> b >> c >> d >> h >> f;
    inih = h;
    inif = f;
    for (int i = 0; i < 10001; i++) {
      hy = a * h - b * f;
      fy = c * f + d * h;
      if (isinf(hy) ){
        fy = hy;
        break;
      } else if (isinf(fy)){
        hy= -fy;
        break;
      }

      if (i != 10000) {
        h = hy;
        f = fy;
      }
    }

    if (hy / inih > 0 && hy / inih < 2 && fy / inif > 0 && fy / inif < 2) {
      cout << "Ecological balance will develop." << '\n';
    } else if (isinf(hy) && hy > 0 && isinf(fy) && fy > 0) {
      cout << "Both hares and foxes will overgrow." << '\n';
    } else if (isinf(hy) && hy > 0 && isinf(fy) && fy < 0) {
      cout << "Hares will overgrow while foxes will die out." << '\n';
    } else if (isinf(hy) && hy < 0 && isinf(fy) && fy < 0) {
      cout << "Both hares and foxes will die out." << '\n';

    } else if (isinf(hy) && hy < 0 && isinf(fy) && fy > 0) {
      cout << "Hares will die out while foxes will overgrow." << '\n';
    } else {
      cout << "Chaos will develop." << '\n';
    }
  }
  return 0;
}