/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t,w,type;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int a[305][5005],ti[305][5005],minn[305],tim[305];
int main(){
    int r,c,m,opr,u,v,w,ch;
    scanf("%d %d %d",&r,&c,&m);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            heap.push({i,j,1,0,1});
    for(int k=1;k<=m;k++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&u,&v,&w);
            a[u][v] = w;
            ti[u][v] = k;
            heap.push({u,v,k,w,opr});
        }else if(opr == 2){
            scanf("%d %d",&u,&w);
            minn[u] = w;
            tim[u] = k;
            heap.push({u,0,k,w,opr});
        }else if(opr == 3){
            scanf("%d %d",&u,&v);
            if(ti[u][v]>tim[u]) printf("%d\n",a[u][v]);
            else                printf("%d\n",minn[u]);
        }else if(opr == 4){
            while(!heap.empty()){
                now = heap.top();
                if(now.type == 1){
                    if(now.w != a[now.i][now.j] || tim[now.i]>now.t) heap.pop();
                    else{
                        printf("%d\n",now.w);
                        break;
                    }
                }else if(now.type == 2){
                    if(tim[now.i]!=now.t){
                        heap.pop();
                        continue;
                    }
                    for(int i=1;i<=c;i++){
                        ch = 0;
                        if(ti[now.i][i]<now.t){
                            printf("%d\n",now.w);
                            ch = 1;
                            break;
                        }
                    }
                    if(ch)  break;
                    heap.pop();
                }
            }
        }
    }
    return 0;
}
