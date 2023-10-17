#include <bits/stdc++.h>
#include <functional>
#include <string>
// https://chat.openai.com/c/c27069a1-e272-49d7-9268-01e126a62630
using namespace std;
// https://github.com/t3nsor/SPOJ/blob/master/bulk.cpp

struct point {
  int x;
  int y;
  int z; 
};

struct face{
  vector<point> points;
};



struct face_edge{
  int f;
  int v;
  int d;

};

struct line{
  point p;
  int unit;
  friend bool operator==(const line& l1, const line& l2 ){
    return l1.p.x == l2.p.x && l1.p.y == l2.p.y &&
            l1.p.z == l2.p.z && l1.unit == l2.unit;
  }
};

// Hash function for 'line' structures
template <> struct hash<line>{
  size_t operator()(const line& l) const {
    const long long w = l.p.x + (l.p.y <<10) + (l.p.z << 20);
    return hash<long long>{}((w<<3)+l.unit);
  }
}





int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int F;
  cin >>F;
  vector<face> faces;

  

  return 0;
}