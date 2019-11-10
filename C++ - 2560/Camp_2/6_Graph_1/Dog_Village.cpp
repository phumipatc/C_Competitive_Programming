/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int ni,nj,day;
};
int table[1200][1200],mark[1200][1200],dir[4]={1,-1,0,0},dic[4]={0,0,1,-1};
queue< A> q;
int main()
{
    A temp,temp2;
    int n,m,i,j,nexti,nextj,ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&table[i][j]);
            if(table[i][j]==0){
                temp.ni=i;
                temp.nj=j;
                temp.day=0;
                q.push(temp);
                mark[i][j]=1;
            }
        }
    }
    while(!q.empty()){
        temp=q.front();
        q.pop();
        //printf("%d %d %d\n",temp.ni,temp.nj,temp.day);
        for(i=0;i<4;i++){
            nexti=temp.ni+dir[i];
            nextj=temp.nj+dic[i];
            //printf("%d %d\n",nexti,nextj);
            if(nexti<=0 || nextj <=0 || nexti>n || nextj>m) continue;
            //printf("Pass case 1\n");
            if(mark[nexti][nextj]==1)   continue;
            //printf("Pass case 2\n");
            mark[nexti][nextj]=1;
            if(table[nexti][nextj]<=temp.day+1) continue;
            //printf("Pass case 3\n");
            temp2.ni=nexti;
            temp2.nj=nextj;
            temp2.day=temp.day+1;
            q.push(temp2);
            table[nexti][nextj]=0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(table[i][j]!=0)  ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
