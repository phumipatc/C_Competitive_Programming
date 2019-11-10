/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int w,v,t,nw,id,type;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
struct B{
    int w,v,t,nw,id;
    bool operator < (const A&o) const{
        return t>o.t;
    }
};
B temp;
priority_queue<A > heap;
priority_queue<B > magic;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    n+=m;
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d",&type);
            if(type == 1){
                scanf("%d %d",&now.w,&now.v);
                heap.push({now.w,now.v,200010,0,i,1});
            }else if(type == 2){
                scanf("%d %d %d",&now.w,&now.v,&now.t);
                heap.push({now.w,now.v,now.t,0,i,2});
            }else if(type == 3){
                scanf("%d %d %d %d",&now.w,&now.v,&now.t&now.nw);
                heap.push({now.w,now.v,now.t,now.nw,i,3});
                magic.push({now.w,now.v,now.t,now.nw,i});
            }
        }else{
        }
    }
	return 0;
}
