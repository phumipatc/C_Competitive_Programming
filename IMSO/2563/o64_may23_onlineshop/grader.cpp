#include "onlineshop.cpp"
#include <cstdio>
#include <cassert>

static int v[100010];
static int n;
static long long total_value;
static int ccount;

bool sell_price(int p)
{
  assert(ccount < n);

  ccount++;
  if(p <= v[ccount-1]) {
    total_value += (long long)(p);
    return true;
  } else {
    return false;
  }
}

int main()
{
  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%d",&v[i]);
  }

  ccount = 0;
  total_value = 0;
  sell_all(n);

  printf("%lld\n", total_value);
}
