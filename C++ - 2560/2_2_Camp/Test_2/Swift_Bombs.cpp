/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long i,j,dis;
};
long long mark[1100][1100],t[1000100],dir[4]={1,-1,0,0},dic[4]={0,0,1,-1};
queue< A> que;
int main(){
    long long i,j,n,m,q,dis;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(i=1;i<=m;i++){
        long long x,y;
        scanf("%lld %lld",&x,&y);
        mark[x][y]=1;
    }
    long long sti,stj;
    scanf("%lld %lld",&sti,&stj);
    que.push({sti,stj,0});
    mark[sti][stj]=1;
    while(!que.empty()){
        i=que.front().i;
        j=que.front().j;
        dis=que.front().dis;
        que.pop();
        t[dis]++;
//        printf("%lld %lld %lld\n",i,j,dis);
        for(long long k=0;k<4;k++){
            long long ni=i+dir[k];
            long long nj=j+dic[k];
            if(mark[ni][nj] || ni<1 || nj<1 || ni>n || nj>n)    continue;
            mark[ni][nj]=1;
            que.push({ni,nj,dis+1});
        }
    }
    for(long long i=0;i<=1000000;i++)
        t[i]+=t[i-1];
    while(q--){
        scanf("%lld",&dis);
        printf("%lld\n",t[dis]);
    }
    return 0;
}
