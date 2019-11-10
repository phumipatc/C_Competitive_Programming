/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,v,t;
    bool operator < (const A&o) const{
        return v>o.v;
    }
};
A now;
priority_queue<A > heap;
int a[310][5010][2],rr[310][2];
int main(){
    int r,c,m,x,y,v,opr,ch;
    scanf("%d %d %d",&r,&c,&m);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            heap.push({i,j,0,0});
    for(int k=1;k<=m;k++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&x,&y,&v);
            a[x][y][0] = v;
            a[x][y][1] = k;
            heap.push({x,y,v,k});
        }else if(opr == 2){
            scanf("%d %d",&x,&v);
            rr[x][0] = v;
            rr[x][1] = k;
            heap.push({x,0,v,k});
        }else if(opr == 3){
            scanf("%d %d",&x,&y);
            if(rr[x][1]>a[x][y][1])
                printf("%d\n",rr[x][0]);
            else
                printf("%d\n",a[x][y][0]);
        }else if(opr == 4){
            while(!heap.empty()){
                now = heap.top();
                if(now.j == 0){
                    if(rr[now.i][1]>now.t){
                        heap.pop();
                        continue;
                    }
                    ch = 0;
                    for(int j=1;j<=c;j++){
                        if(a[now.i][j][1]<now.t){
                            ch = 1;
                            break;
                        }
                    }
                    if(!ch){
                        heap.pop();
                        continue;
                    }
                }else{
                    if(a[now.i][now.j][1]>now.t || rr[now.i][1]>now.t){
                        heap.pop();
                        continue;
                    }
                }
                printf("%d\n",now.v);
                break;
            }
        }
    }
	return 0;
}
/*
3 3 14
3 1 2
4
2 1 100
2 2 10
2 3 40
4
1 2 1 50
1 2 3 200
4
1 3 3 25
3 3 2
4
1 2 2 60
4
*/
