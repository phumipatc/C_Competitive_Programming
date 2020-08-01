#include <bits/stdc++.h>
#include "castle.h"
using namespace std;

int N, M, Q, Y;
int mark[100010], walk[100010];
vector<int> A, B;
vector<pair<int, int>> g[100010];
queue<int> que;
int main()
{
	castle_init(N, M, Q, Y);
	castle_read_map(A, B);
	for (int i = 0; i < A.size(); i++)
		g[A[i]].push_back({B[i], i}), g[B[i]].push_back({A[i], i});
	while (Q--)
	{
		int T, X, Y;
		castle_read_event(T, X, Y);
		if (N <= 1000 && Q <= 1000)
		{
			if (T == 2)
			{
				memset(walk, 0, sizeof walk);
				que.push(X);
				walk[X] = 1;
				while (!que.empty())
				{
					int now = que.front();
					que.pop();
					if (now == Y)
					{
						castle_answer(1);
						break;
					}
					for (auto x : g[now])
					{
						if (mark[x.second])
							continue;
						if (walk[x.first])
							continue;
						walk[x.first] = 1;
						que.push(x.first);
					}
				}
				if (!walk[Y])
					castle_answer(0);
				while (!que.empty())
					que.pop();
			}
			else
			{
				mark[X] = 1;
			}
		}else{
			
		}
	}
}
