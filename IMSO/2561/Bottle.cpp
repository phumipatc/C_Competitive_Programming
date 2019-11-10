/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int height,pos,l,r;
    bool operator < (const A&o) const{
        return height<o.height;
    }
};
A now;
priority_queue< A> heap;
int mark[100100];
int main(){
    int n,m,num,countt;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        heap.push({num,i,i-1,i+1});
    }
    mark[0] = mark[n+1] = 1;
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        countt = 0;
        while(!heap.empty() && heap.top().height>num){
            now = heap.top();
            heap.pop();
            if(mark[now.pos] && mark[now.pos]<i) continue;
            if(!mark[now.l])    mark[now.l] = i,countt++;
            if(!mark[now.pos])  mark[now.pos] = i,countt++;
            if(!mark[now.r])    mark[now.r] = i,countt++;
        }
        printf("%d\n",countt);
    }
    return 0;
}
