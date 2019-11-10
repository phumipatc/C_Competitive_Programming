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
struct B{
    long long dis,value;
    bool operator < (const B&o) const{
        return dis<o.dis;
    }
};
B st[1000100];
queue< A> que;
priority_queue< long long> heap;
long long a[1100][1100],mark[1100][1100],dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
A now,ne;
int main(){
    long long n,idx=1;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    que.push({1,1,0});
    while(!que.empty()){
        now=que.front();
        que.pop();
        if(mark[now.i][now.j])  continue;
        mark[now.i][now.j]=1;
        st[idx].dis=now.dis;
        st[idx++].value=a[now.i][now.j];
        for(long long k=0;k<4;k++){
            ne.i=now.i+dir[0][k];
            ne.j=now.j+dir[1][k];
            if(ne.i<1 || ne.j<1 || ne.i>n || ne.j>n)    continue;
            que.push({ne.i,ne.j,now.dis+1});
        }
    }
    sort(st+1,st+idx+1);
    for(long long i=1;i<=idx;i++){
        if(st[i].value<=0)   continue;
        if(heap.size()<st[i].dis)
            heap.push(st[i].value*(-1));
        else if(!heap.empty() && heap.top()*(-1)<st[i].value){
            heap.pop();
            heap.push(st[i].value*(-1));
        }
    }
    long long ans=0;
    while(!heap.empty()){
        ans-=heap.top();
        heap.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
