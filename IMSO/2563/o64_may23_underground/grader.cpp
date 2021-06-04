#include "underground_sub.cpp"
#include <vector>
#include <cstdio>

using namespace std;

static vector<vector<int>> A;

int main()
{
  int R,C;

  scanf("%d %d",&R,&C);
  for(int i=0; i<R; i++) {
    vector<int> row;
    for(int j=0; j<C; j++) {
      int aa;

      scanf("%d",&aa);
      row.push_back(aa);
    }
    A.push_back(row);
  }

  int result = dig_paths(R, C, A);

  printf("%d\n", result);
  return 0;
}
/*
5 6
1 20 20 25 50 1
2 1 45 4 1 1
65 1 67 2 50 1
3 1 2 1 52 3
1 95 85 25 57 1
*/