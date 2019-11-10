/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,ch;
    bool operator <(const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int a[60][60],dis[60][60][2],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int n,sti,stj,eni,enj;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j][0] = dis[i][j][1] = 1e9;
    dis[sti][stj][0] = 0;
    heap.push({sti,stj,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
//        printf("%d %d %d %d\n",now.i,now.j,now.w,now.ch);
        if(now.i == eni && now.j == enj && now.ch == 1){
            printf("%d\n",dis[eni][enj][1]);
            break;
        }
        for(int k=0;k<4;k++){
            int ii = now.i+dir[0][k],jj = now.j+dir[1][k],ch = now.ch;
            if(ii<1 || jj<1 || ii>n || jj>n)    continue;
            if(a[ii][jj]<0)                     ch = !ch;
            if(dis[ii][jj][ch]>now.w+abs(a[ii][jj])){
                dis[ii][jj][ch] = now.w+abs(a[ii][jj]);
                heap.push({ii,jj,dis[ii][jj][ch],ch});
            }
        }
    }
	return 0;
}
