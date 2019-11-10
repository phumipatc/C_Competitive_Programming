/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],block[350];
int main(){
    int n,q,sq,st,en,ans;
    scanf("%d %d",&n,&q);
    sq = (int)sqrt(n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<sq;i++)
        block[i] = -1e9;
    for(int i=0;i<n;i++)
        block[i/sq] = max(block[i/sq],a[i]);
    while(q--){
        scanf("%d %d",&st,&en);
        ans = -1e9;
        for(int i=st;i<=en;){
            if(i%sq == 0 && i+sq-1<=en){
                ans = max(ans,block[i/sq]);
                i+=sq;
            }else{
                ans = max(ans,a[i]);
                i++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
