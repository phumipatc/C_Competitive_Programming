#include "blindwalk.h"
#include <cstdio>
#include <cassert>

static const int MAX_N = 600;
static const long long T1_TIME = 2596418101;
static const long long T2_TIME = 840634349;
static const long long T3_TIME = 590846489;

static const long long W_TIME[] = {T1_TIME, T2_TIME, T3_TIME};
static const long long INFINITY = (T1_TIME + 1) * 1000;
static int n,m;
static long long distance[MAX_N][MAX_N];
static long long output_distance[MAX_N][MAX_N];

static int counter;

long long ask(int s, int t)
{
  counter++;

  assert(counter <= 250000);
    
  return distance[s][t];
}

void fw(long long d[][MAX_N])
{
  for(int k=0; k<n; k++)
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
	if(d[i][j] > d[i][k] + d[k][j]) {
	  d[i][j] = d[i][k] + d[k][j];
	}
}

void read_and_init_graph()
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++) {
      distance[i][j] = INFINITY;
      output_distance[i][j] = INFINITY;
    }
  
  for(int i=0; i<m; i++) {
    int u,v,t;
    scanf("%d %d %d",&u,&v,&t);
    
    distance[u][v] = W_TIME[t-1];
    distance[v][u] = W_TIME[t-1];
  }

  for(int u=0; u<n; u++) {
    distance[u][u] = 0;
    output_distance[u][u] = 0;
  }
  
  fw(distance);
}

void check(std::vector<std::vector<int>>& g)
{
  printf("%d\n", (int)g.size());
  for(auto ei = g.begin(); ei != g.end(); ei++) {
    int u,v,t;

    u = (*ei)[0];
    v = (*ei)[1];
    t = (*ei)[2];

    assert(u < n);
    assert(u >= 0);
    assert(v < n);
    assert(v >= 0);
    assert(t <= 3);
    assert(t >= 1);

    printf("%d %d %d\n",u,v,t);
    output_distance[u][v] = W_TIME[t-1];
    output_distance[v][u] = W_TIME[t-1];
  }

  fw(output_distance);

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(output_distance[i][j] != distance[i][j]) {
	if(output_distance[i][j] != INFINITY)
	  printf("Error wrong distance (%d to %d). Expected: %lld, Answer: %lld\n",
		 i, j,
		 distance[i][j],
		 output_distance[i][j]);
	else
	  printf("Error wrong distance (%d to %d). Expected: %lld, Answer: infinity\n",
		 i, j,
		 distance[i][j]);
	return;
      }
  printf("OK\n");
}

int main()
{
  scanf("%d %d",&n,&m);
  read_and_init_graph();

  counter = 0;
  
  std::vector<std::vector<int>> result = build_graph(n);

  printf("%d call(s) to ask\n", counter);
  
  check(result);
}
