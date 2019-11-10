/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A a[2010];
struct B{
    int v,w;
    bool operator < (const B&o) const{
        if(w!=o.w)  return w>o.w;
        else        return v>o.v;
    }
};
B now;
priority_queue<B > heap;
vector<B > g[2010];
int mark[2010];
int main(){
    int n,m,k,countt = 3;
    char temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&temp);
            if(temp == '.') continue;
            if(temp == 'A') a[1] = {i,j};
            if(temp == 'B') a[2] = {i,j};
            if(temp == 'X') a[countt++] = {i,j};
        }
    }
    for(int i=1;i<countt;i++){
        for(int j=i+1;j<countt;j++){
            if(abs(a[i].i-a[j].i)+abs(a[i].j-a[j].j)>k) continue;
            g[i].push_back({j,abs(a[i].i-a[j].i)+abs(a[i].j-a[j].j)});
            g[j].push_back({i,abs(a[i].i-a[j].i)+abs(a[i].j-a[j].j)});
        }
    }
    heap.push({1,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(mark[now.v])   continue;
        mark[now.v]=1;
        if(now.v == 2){
            printf("%d\n",now.w);
            return 0;
        }
        for(auto x:g[now.v]){
            heap.push({x.v,x.w+now.w});
        }
    }
    printf("-1\n");
	return 0;
}
