/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,v;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v<o.v;
        else        return id<o.id;
    }
};
A now;
priority_queue< A> heap;
int point[1000100],mark[1000100];
int main(){
    int n,l,r,m,u,v;
    char opr;
    scanf("%d %d %d",&n,&l,&r);
    for(int i=1;i<=n;i++)
        heap.push({i,0});
    m = l+r;
    while(m--){
        scanf(" %c",&opr);
        if(opr == 'L'){
            scanf("%d %d",&u,&v);
            point[v]++;
            heap.push({v,point[v]});
        }else if(opr == 'C'){
            scanf("%d %d",&u,&v);
            point[v]+=3;
            heap.push({v,point[v]});
        }else if(opr == 'R'){
            while(!heap.empty()){
                now = heap.top();
                if(mark[now.id]){
                    heap.pop();
                    continue;
                }
                printf("%d\n",now.id);
                break;
            }
        }else{
            while(!heap.empty()){
                now = heap.top();
                heap.pop();
                if(mark[now.id])    continue;
                mark[now.id] = 1;
                break;
            }
        }
    }
	return 0;
}
