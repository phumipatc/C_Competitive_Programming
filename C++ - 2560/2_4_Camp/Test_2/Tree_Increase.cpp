/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[300001];
int mic[300001];
int main()
{
    int n,i,j,r,s,maxx=-1;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&r,&s);
        if(r>s) g[r].push_back(s);
        else    g[s].push_back(r);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<(int)g[i].size();j++)
            mic[i]=max(mic[i],mic[g[i][j]]);
        mic[i]++;
        maxx=max(maxx,mic[i]);
    }
    printf("%d\n",maxx);
    return 0;
}
