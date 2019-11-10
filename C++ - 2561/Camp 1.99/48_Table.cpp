/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,t,id;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int a[310][5010][2],r[310][2];
int main(){
    int row,column,n,x,y,w,opr;
    scanf("%d %d %d",&row,&column,&n);
    for(int i=1;i<=row;i++)
        for(int j=1;j<=column;j++)
            heap.push({i,j,0,0,1});
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&x,&y,&w);
            heap.push({x,y,w,i,1});
            a[x][y][0] = w,a[x][y][1] = i;
        }else if(opr == 2){
            scanf("%d %d",&x,&w);
            heap.push({x,0,w,i,2});
            r[x][0] = w,r[x][1] = i;
        }else if(opr == 3){
            scanf("%d %d",&x,&y);
            if(a[x][y][1]>r[x][1]){
                printf("%d\n",a[x][y][0]);
            }else{
                printf("%d\n",r[x][0]);
            }
        }else if(opr == 4){
            while(!heap.empty()){
                now = heap.top();
                if(now.id == 1){
                    if(a[now.i][now.j][0] != now.w || r[now.i][1]>now.t){
                        heap.pop();
                        continue;
                    }
                    printf("%d\n",now.w);
                    break;
                }else{
                    if(r[now.i][1]>now.t){
                        heap.pop();
                        continue;
                    }
                    int ch = 0;
                    for(int j=1;j<=column;j++){
                        if(a[now.i][j][1]<now.t){
                            printf("%d\n",now.w);
                            ch = 1;
                            break;
                        }
                    }
                    if(!ch){
                        heap.pop();
                        continue;
                    }
                    break;
                }
            }
        }
    }
	return 0;
}
