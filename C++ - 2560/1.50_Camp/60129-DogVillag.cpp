#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],h[1005][1005],m1[]={0,0,1,-1},m2[]={1,-1,0,0};
queue<pair<int,int>> q;
int main()
{
    int r,c,x,y,nx,ny,sum=0;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
                q.push(make_pair(i,j));
                sum++;
            }
        }
    }
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        //printf("x %d  y %d\n",x,y);
        for(int k=0;k<4;k++)
        {
            nx=x+m1[k];
            ny=y+m2[k];
            if(nx>=0 && nx<r && ny>=0 && ny<c && a[nx][ny]>h[x][y]+1 && h[nx][ny]==0)
            {
                //printf(" nx %d  ny %d\n",nx,ny);
                sum++;
                h[nx][ny]=h[x][y]+1;
                q.push(make_pair(nx,ny));
            }
        }
    }
    printf("%d\n",r*c-sum);
}
/*
4 4
0 1 3 2
4 3 1 1
2 0 1 1
0 4 1 9

*/
