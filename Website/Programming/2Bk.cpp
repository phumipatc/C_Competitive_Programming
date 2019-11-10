/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,maxx;
    bool operator < (const A&o) const{
        return maxx>o.maxx;
    }
};
A now,nextt;
priority_queue< A> heap;
int a[1005][1005],dis[1005][1005],dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
int main(){
    int n,x1,x2,y1,y2,ch = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            dis[i][j] = 1e9;
            if(!a[i][j] && !ch)
                ch = 1,x1 = i,y1 = j,dis[i][j] = 0;
            else if(!a[i][j] && ch)
                x2 = i,y2 = j;
        }
    }
    heap.push({x1,y1,0});
    while(!heap.empty()){
        now = heap.top();
//        printf("now : %d %d %d\n",now.i,now.j,now.maxx);
        heap.pop();
        for(int k=0;k<4;k++){
            nextt.i = now.i+dir[0][k];
            nextt.j = now.j+dir[1][k];
            nextt.maxx = max(a[nextt.i][nextt.j],now.maxx);
//            printf("nextt : %d %d %d\n",nextt.i,nextt.j,nextt.maxx);
            if(dis[nextt.i][nextt.j]>nextt.maxx){
                dis[nextt.i][nextt.j] = nextt.maxx;
                heap.push({nextt.i,nextt.j,nextt.maxx});
            }
        }
    }
    printf("%d\n",dis[x2][y2]);
    return 0;
}
