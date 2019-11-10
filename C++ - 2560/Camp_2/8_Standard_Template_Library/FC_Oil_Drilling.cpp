/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> s;
set<int>::iterator it,it2;
int main()
{
	int i,j,n,k,x;
	scanf("%d %d",&n,&k);
	while(k--)
	{
		scanf("%d",&x);
		if(s.empty())
			printf("%d\n",n);
		else
		{
			it = it2 = s.lower_bound(x);
			it--;
			if(it2==s.begin())
			{
				printf("%d\n",(*it2)-x);
			}
			else if(it2==s.end())
			{
				printf("%d\n",x-(*it));
			}
			else
			{
				printf("%d\n",min((*it2)-x,x-(*it)));
			}
		}
		s.insert(x);
	}
	return 0;
}
