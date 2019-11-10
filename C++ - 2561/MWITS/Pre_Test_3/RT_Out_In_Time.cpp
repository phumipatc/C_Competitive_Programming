/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
A now;
queue<A > que;
char a[32][32];
int mark[32][32],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int q,r,c,t,sti,stj,eni,enj,walk,ni,nj,all;
    scanf("%d",&q);
    while(q--){
        walk = 1e9,all = 0;
        scanf("%d %d %d",&r,&c,&t);
        for(int i=1;i<=r;i++)
            scanf(" %s",a[i]+1);
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
        memset(mark,0,sizeof mark);
        que.push({sti,stj,0});
        while(!que.empty()){
            now = que.front();
            que.pop();
            if(mark[now.i][now.j])  continue;
            mark[now.i][now.j] = 1;
            all++;
            if(now.i == eni && now.j == enj)    walk = now.w;
            for(int k=0;k<4;k++){
                ni = now.i+dir[0][k],nj = now.j+dir[1][k];
                if(ni<1 || nj<1 || ni>r || nj>c)    continue;
                if(mark[ni][nj])                    continue;
                if(a[ni][nj] == '#')                continue;
                que.push({ni,nj,now.w+1});
            }
        }
        if(walk>t){
            printf("-1\n");
            continue;
        }
        printf("%d\n",(walk+1)+min((t-walk)/2,all-(walk+1)));
    }
	return 0;
}
