/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > p[12];
int countt[12];
int main(){
    int n,m,k,minn,near;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        scanf("%d %d",&p[i].first,&p[i].second);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            minn = 1e9;
            for(int l=1;l<=k;l++){
                if(minn>abs(i-p[l].first)+abs(j-p[l].second)){
                    minn = abs(i-p[l].first)+abs(j-p[l].second);
                    near = l;
                }
            }
            countt[near]++;
        }
    }
    for(int i=1;i<=k;i++)
        printf("%d\n",countt[i]);
    return 0;
}
