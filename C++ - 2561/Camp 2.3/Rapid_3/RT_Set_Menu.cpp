/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int v[25],mark[25],countt[25],a[5];
int main(){
    int k,sv,temp,n,ans = 0,sum;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&v[i]);
    scanf("%d",&sv);
    for(int i=1;i<=4;i++){
        scanf("%d",&a[i]);
        mark[a[i]] = 1;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        if(mark[temp])  countt[temp]++;
        else            ans+=v[temp];
    }
    while(1){
        int ch = 1,sum = 0;
        for(int i=1;i<=4;i++){
            if(countt[a[i]]){
                ch = 0;
                sum+=v[a[i]];
            }
        }
        if(ch)  break;
        ans+=min(sum,sv);
        for(int i=1;i<=4;i++){
            if(countt[a[i]]){
                countt[a[i]]--;
            }
        }
    }
    printf("%d",ans);
	return 0;
}
