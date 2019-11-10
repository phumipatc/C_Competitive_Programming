/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> v[100001];
int LIS[100001],ans[100001];
int main(){
    int n,maxx=0,idx,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        idx=upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx>=1 && LIS[idx-1]==num)   continue;
        if(idx==maxx)   maxx++;
        LIS[idx]=num;
        v[idx].push_back(num);
    }
    printf("%d\n",maxx);
    int now=v[maxx-1][0];
    idx=0;
    ans[idx++]=now;
    for(int i=maxx-2;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]<now){
                now=v[i][j];
                ans[idx++]=now;
                break;
            }
        }
    }
    for(int i=idx-1;i>=0;i--)
        printf("%d ",ans[i]);
    return 0;
}
