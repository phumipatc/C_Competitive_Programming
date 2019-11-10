/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
PII p[100100];
int mic[10100];
int main()
{
    int k,m,n,maxx=-1,i;
    scanf("%d %d %d",&k,&n,&m);
    for(i=0;i<m;i++)
        scanf("%d %d",&p[i].first,&p[i].second);
    sort(p,p+m);
    for(i=2;i<=n;i++)   mic[i]=1e9;
    for(i=0;i<m;i++){
        if(mic[p[i].second]>mic[p[i].first]+1)
            mic[p[i].second]=mic[p[i].first]+1;
    }
    for(i=n;i>=1;i--){
        if(mic[i]<=k){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
