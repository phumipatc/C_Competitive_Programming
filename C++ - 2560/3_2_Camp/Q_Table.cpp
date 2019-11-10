/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,t;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
pair<int,int> table[305][5005],row[305];
int main(){
    int r,c,m,opr,x,y,w,ch;
    scanf("%d %d %d",&r,&c,&m);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            heap.push({i,j,0,0});
    for(int l=1;l<=m;l++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&x,&y,&w);
            table[x][y].first = w;
            table[x][y].second = l;
            heap.push({x,y,w,l});
        }else if(opr == 2){
            scanf("%d %d",&x,&w);
            row[x].first = w;
            row[x].second = l;
            heap.push({x,0,w,l});
        }else if(opr == 3){
            scanf("%d %d",&x,&y);
            if(table[x][y].second>row[x].second)
                printf("%d\n",table[x][y].first);
            else
                printf("%d\n",row[x].first);
        }else if(opr == 4){
            while(!heap.empty()){
                now = heap.top();
                if(now.j == 0){
                    if(now.t<row[now.i].second){
                        heap.pop();
                        continue;
                    }
                    ch = 1;
                    for(int j=1;j<=c;j++)
                        if(now.t >= table[now.i][j].second)
                            ch = 0;
                    if(ch){
                        heap.pop();
                        continue;
                    }
                    printf("%d\n",now.w);
                    break;
                }else{
                    if(now.t<row[now.i].second || now.t<table[now.i][now.j].second){
                        heap.pop();
                        continue;
                    }
                    printf("%d\n",now.w);
                    break;
                }
            }
        }
    }
    return 0;
}
