/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[300100];
int mic[300100];
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
        for(j=0;j<(int)g[i].size();j++){
            if(mic[g[i][j]]>mic[i])
                mic[i]=mic[g[i][j]];
        }
        mic[i]++;
        if(mic[i]>maxx)
            maxx=mic[i];
    }
    printf("%d\n",maxx);
    return 0;
}
