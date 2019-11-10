#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,dist,gate;
    bool operator < (const A&o) const{
        if(dist<o.dist) return false;
        else            return true;
    }
};
priority_queue< A> q;
A temp;
int a[100][100][2],b[100][100];
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int main()
{
    int n,i,j,si,sj,ei,ej,di,k,nexti,nextj,g;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
            a[i][j][0]=a[i][j][1]=1000000000;
        }
    }
    scanf("%d %d %d %d",&si,&sj,&ei,&ej);
    temp.dist=0,temp.i=si,temp.j=sj,temp.gate=0;
    q.push(temp);
    a[si][sj][0]=1;
    while(!q.empty()){
        i=q.top().i,j=q.top().j,di=q.top().dist,g=q.top().gate;
        if(i==ei && j==ej && q.top().gate==1){
            printf("%d\n",di);
            return 0;
        }
        q.pop();
        for(k=0;k<4;k++){
            nexti=i+d[k][0],nextj=j+d[k][1];
            if(nexti<1 || nextj<1 || nexti>n || nextj>n)
                continue;
            temp.gate=g;
            if(b[nexti][nextj]<0)
                temp.gate=g^1;
            if(a[nexti][nextj][temp.gate]==1)
                continue;
            temp.i=nexti,temp.j=nextj,temp.dist=di+abs(b[nexti][nextj]);
            q.push(temp);
            a[nexti][nextj][temp.gate]=1;
        }
    }
    return 0;
}
