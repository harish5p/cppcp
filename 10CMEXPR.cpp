#include <bits/stdc++.h>
using namespace std;

//  shunting yard algorithm
// https://chat.openai.com/c/ecc68770-050c-4bde-b387-a7950de0c5e8
// https://chat.openai.com/c/99b85e70-661f-4763-88ea-08b7bf9b5f21
struct Node {
  char c;
  Node *l;
  Node *r;
  void print() {
    if (c >= 'a') {
      putchar(c);
    } else if (c == '+') {
      l->print();
      putchar('+');
      r->print();
    } else if (c == '-') {
      l->print();
      putchar('-');
      if (r->c == '+' || r->c == '-') {
        putchar('(');
        r->print();
        putchar(')');
      } else {
        r->print();
      }
    } else if (c == '*') {
      if (l->c == '+' || l->c == '-') {
        putchar('(');
        l->print();
        putchar(')');
      } else {
        l->print();
      }
      putchar('*');
      if (r->c == '+' || r->c == '-') {
        putchar('(');
        r->print();
        putchar(')');
      } else {
        r->print();
      }
    } else {
      if (l->c == '+' || l->c == '-') {
        putchar('(');
        l->print();
        putchar(')');
      } else {
        l->print();
      }
      putchar('/');
      if (r->c < 'a') {
        putchar('(');
        r->print();
        putchar(')');
      } else {
        r->print();
      }
    }
  }
};

Node pool[10000000];
int ptr = 0;
Node *stk1[300];
char stk2[300];
int sp1;
int sp2;
int prec[256] = {0};

int main() {
  prec['+'] = 1;
  prec['-'] = 1;
  prec['*'] = 2;
  prec['/'] = 2;
  int N;
  char s[300];
  cin >> N;
  cin.ignore();
  Node *n;
  while (N--) {
    sp1 = 0;
    cin.getline(s, sizeof(s));
    for (int i = 0; s[i]; i++) {
      if (s[i] >= 'a') {
        Node *new_node = pool + ptr;
        stk1[sp1] = new_node;
        sp1++;
        new_node->c = s[i];
        ptr++;
      } else if (s[i] == '(') {

        stk2[sp2] = '(';
        sp2++;
      } else if (s[i] == ')') {
        while (stk2[--sp2] != '(') {
          n = pool + ptr;
          ptr++;
          n->c = stk2[sp2];
          n->l = stk1[sp1 - 2];
          n->r = stk1[sp1 - 1];
          stk1[sp1 - 2] = n;
          sp1--;
        }
      } else {
        while (sp2 && prec[stk2[sp2 - 1]] >= prec[s[i]]) {
          n = pool + ptr;
          ptr++;
          n->c = stk2[--sp2];
          n->l = stk1[sp1 - 2];
          n->r = stk1[sp1 - 1];
          stk1[sp1 - 2] = n;
          sp1--;
        }
        stk2[sp2++] = s[i];
      }
    }
    while (sp2) {
      n = pool + ptr;
      ptr++;
      n->c = stk2[--sp2];
      n->l = stk1[sp1 - 2];
      n->r = stk1[sp1 - 1];
      stk1[sp1 - 2] = n;
      sp1--;
    }
    (*stk1)->print();
    puts("");
  }
  return 0;
}
