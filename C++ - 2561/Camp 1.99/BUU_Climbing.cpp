/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int dis[110][110],dir[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
char a[110][110];
int main(){
    int q,r,c,eni,enj,maxx,sti,stj,ii,jj;
    scanf("%d",&q);
    while(q--){
        maxx = -1;
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j] == '#')  continue;
                if(a[i][j]-'0'>maxx){
                    maxx = a[i][j]-'0';
                    eni = i;
                    enj = j;
                }
            }
        }
        scanf("%d %d",&sti,&stj);
        sti++,stj++;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                dis[i][j] = 1e9;
        heap.push({sti,stj,0});
        dis[sti][stj] = 0;
        int ch = 1;
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
//            printf("%d %d %d\n",now.i,now.j,now.w);
            if(now.i == eni && now.j == enj){
                printf("%d\n",dis[eni][enj]);
                ch = 0;
                break;
            }
            for(int k=0;k<8;k++){
                ii = now.i+dir[0][k],jj = now.j+dir[1][k];
                if(ii<1 || jj<1 || ii>r || jj>c)    continue;
                if(a[ii][jj] == '#')                continue;
                if(dis[ii][jj]>now.w+(abs(a[ii][jj]-a[now.i][now.j])+1)*(abs(a[ii][jj]-a[now.i][now.j])+1)){
                    dis[ii][jj] = now.w+(abs(a[ii][jj]-a[now.i][now.j])+1)*(abs(a[ii][jj]-a[now.i][now.j])+1);
                    heap.push({ii,jj,dis[ii][jj]});
                }
            }
        }
        if(ch)  printf("NO\n");
        while(!heap.empty())    heap.pop();
    }
	return 0;
}
/*
2
5 5
11111
1###1
12341
12221
12221
0 0
3 3
1#3
2#3
##4
1 0
*/
