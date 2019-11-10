/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
};
A a[310];
priority_queue<int > heap;
map<int ,int > mapp;
int dp[610][610],plane[610][610];
int park(int l,int r){
    if(dp[l][r]!=-1)    return dp[l][r];
    if(l == r)          return plane[l][r];
    dp[l][r] = plane[l][r];
    int temp = 0;
    for(int i=l;i<r;i++){
        temp = max(temp,park(l,i)+park(i+1,r));
    }
    dp[l][r]+=temp;
    return dp[l][r];
}
int main(){
    int q,now,n,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].st,&a[i].en);
            a[i].en--;
            heap.push(-a[i].st);    heap.push(-a[i].en);
        }
        countt = 1;
        while(!heap.empty()){
            now = -heap.top();
            heap.pop();
            if(mapp[now])   continue;
            mapp[now] = countt++;
        }
        for(int i=1;i<=n;i++)
            plane[mapp[a[i].st]][mapp[a[i].en]]++;
        for(int i=1;i<=countt;i++){
            for(int j=1;j<=countt-i+1;j++){
                for(int k=j;k<i+j-1;k++)
                    dp[j][i+j-1]=max(dp[j][i+j-1],dp[j][k]+dp[k+1][i+j-1]);
                dp[j][i+j-1]+=plane[j][i+j-1];
            }
        }
        printf("%d\n",dp[1][countt]);
        mapp.clear();
        memset(plane,0,sizeof plane);
        memset(dp,0,sizeof dp);
    }
	return 0;
}
