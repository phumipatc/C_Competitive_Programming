/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,k;
    bool operator < (const A&o) const{
        return k > o.k;
    }
};
priority_queue < A> h;
int mark[1010][1010],d[5][5]={{1,0},{0,1},{-1,0},{0,-1}},a[1010][1010];
int main(){
    int n,i,j,nexti,nextj,ch=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==0){
                h.push({i,j,0});
                goto next;
            }
    next:;
    while(!h.empty()){
        A now=h.top();
        h.pop();
        if(mark[now.i][now.j])  continue;
        mark[now.i][now.j] = 1;
        if(a[now.i][now.j] == 0 && ch == 1){
            printf("%d\n",now.k);
            return 0;
        }
        if(a[now.i][now.j] == 0 && ch == 0)
            ch=1;
        for(i=0;i<4;i++){
            nexti = now.i+d[i][0];
            nextj = now.j+d[i][1];
            if(nexti < 1 || nextj < 1 || nexti > n || nextj > n)    continue;
            if(a[nexti][nextj] > now.k)
                h.push({nexti,nextj,a[nexti][nextj]});
            else
                h.push({nexti,nextj,now.k});
        }
    }
    return 0;
}
/*
5
1 1 1 0 1
3 1 1 1 1
0 3 4 3 2
1 1 1 4 1
1 4 2 2 2

3
10 100 10
0 10 100
12 5 0
*/
