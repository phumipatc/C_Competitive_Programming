/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,li,lj,ljr,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int r,c,a[2000100],dp[2000100],dir[2][3] = {{0,1,0},{-1,0,1}};
int change(int i,int j){
    return ((i-1)*c)+j;
}
int main(){
    int k,num;
    cin >> r >> c >> k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> num;
            a[change(i,j)] = num;
        }
    }
    for(int i=1;i<=r*c;i++) dp[i] = -1e9;
    for(int i=1;i<=c;i++){
        dp[i] = a[i];
        heap.push({1,i,1,i,i,a[i]});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int l=0;l<3;l++){
            int ni = now.i+dir[0][l];
            int nj = now.j+dir[1][l];
            if(ni>r || nj>c || ni<1 || nj<1)                continue;
            if(ni == now.li && nj == now.lj)                continue;
            if(dp[change(ni,nj)]>=now.w+a[change(ni,nj)])   continue;
            if(abs(nj-now.ljr)>k)                           continue;
            dp[change(ni,nj)] = now.w+a[change(ni,nj)];
            if(l != 1){
                heap.push({ni,nj,now.i,now.j,now.ljr,dp[change(ni,nj)]});
            }else{
                heap.push({ni,nj,now.i,now.j,now.j,dp[change(ni,nj)]});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=r*c;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
