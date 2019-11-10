/*
TASK: Earn Salary
LANG: C++
AUTHOR: PeaTT~
*/
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector<int>v[100001];
int countt[100001]={0},p[100001]={0},sum[100001]={0};
void bonus(int x)
{
    for(int i=0;i<countt[x];i++)
    {
        p[v[x][i]]+=p[x];
        bonus(v[x][i]);
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        countt[b]++;
       v[b].push_back(a);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[a]+=b;
    }
    bonus(1);
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",p[i]);
    }
	return 0;
}
