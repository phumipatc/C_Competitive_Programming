/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en,id;
    bool operator < (const A&o) const{
        return st<o.st;
    }
};
A a[500010];
priority_queue<int > heap;
int mark[500010];
int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en),a[i].id = i;
    sort(a+1,a+n+1);
    mark[a[1].id] = 1;
    heap.push(-a[1].en);
    for(int i=2;i<=n;i++){
        while(!heap.empty() && -heap.top()<a[i].st)
            heap.pop();
        if(heap.size()<k){
            mark[a[i].id] = 1;
            heap.push(-a[i].en);
        }
    }
    while(m--){
        scanf("%d",&k);
        if(mark[k]) printf("Y ");
        else        printf("N ");
    }
	return 0;
}
