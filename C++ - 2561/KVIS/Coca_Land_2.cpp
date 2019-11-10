/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,v,dead,to;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v>o.v;
        else        return id>o.id;
    }
};
A now;
priority_queue< A> heap;
int main(){
    int n,opr,ch;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d",&now.v,&now.dead);
            now.id = 2;
            heap.push(now);
        }else if(opr == 2){
            scanf("%d",&now.v);
            now.id = 3;
            heap.push(now);
        }else if(opr == 3){
            scanf("%d %d %d",&now.v,&now.dead,&now.to);
            now.id = 1;
            heap.push(now);
        }else{
            ch = 1;
            while(!heap.empty()){
                now = heap.top();
                heap.pop();
                if(now.id == 2){
                    if(now.dead<i) continue;
                    printf("%d\n",now.v);
                    ch = 0;
                    break;
                }else if(now.id == 3){
                    printf("%d\n",now.v);
                    ch = 0;
                    break;
                }else if(now.id == 1){
                    if(now.dead<i){
                        now.v = now.to;
                        now.dead = now.to = 1e9;
                        now.id = 3;
                        heap.push(now);
                        continue;
                    }
                    printf("%d\n",now.v);
                    ch = 0;
                    break;
                }
            }
            if(ch)  printf("GREAN\n");
        }
    }
	return 0;
}
