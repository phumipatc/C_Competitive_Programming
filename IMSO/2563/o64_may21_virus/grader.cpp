#include "virus.h"
#include <cstdio>
#include <cassert>
#include <vector>
 
using namespace std;

static int N, Q, X, Y;

int main() {
  assert(scanf("%d %d %d %d", &N, &Q, &X, &Y) == 4);
  vector<int> vec(Q);
  for (int &L : vec) 
    assert(scanf("%d", &L) == 1);
  initialize(N, X, Y);
  for (int L : vec)
    printf("%d\n", ask(L));
}
