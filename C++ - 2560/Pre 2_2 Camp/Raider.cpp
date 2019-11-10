/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,dis;
};
queue< A> q;
int a[100][150],mark[100][150];
int main(){
    int m,n,i,j,dis;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    if(a[(m/2)][1]==1)
        q.push({m/2,1,1});
    if(a[(m+1)/2][1]==1)
        q.push({(m+1)/2,1,1});
    if(a[(m+3)/2][1]==1)
        q.push({(m+3)/2,1,1});
    while(!q.empty()){
        i=q.front().i,j=q.front().j,dis=q.front().dis;
        q.pop();
        if(i==(m+1)/2 && j==n){
            printf("%d\n",dis);
            break;
        }
        if(i%2==1){
            if(a[i-1][j]!=0)
                if(i-1>0 && (dis+1)%a[i-1][j]==0 && mark[i-1][j]!=dis+1)
                    q.push({i-1,j,dis+1}),mark[i-1][j]=dis+1;
            if(a[i-1][j+1]!=0)
                if(i-1>0 && j+1<=n && (dis+1)%a[i-1][j+1]==0 && mark[i-1][j+1]!=dis+1)
                    q.push({i-1,j+1,dis+1}),mark[i-1][j+1]=dis+1;
            if(a[i][j-1]!=0)
                if(j-1>0 && (dis+1)%a[i][j-1]==0 && mark[i][j-1]!=dis+1)
                    q.push({i,j-1,dis+1}),mark[i][j-1]=dis+1;
            if(a[i][j+1]!=0)
                if(j+1<=n && (dis+1)%a[i][j+1]==0 && mark[i][j+1]!=dis+1)
                    q.push({i,j+1,dis+1}),mark[i][j+1]=dis+1;
            if(a[i+1][j]!=0)
                if(i+1<=m && (dis+1)%a[i+1][j]==0 && mark[i+1][j]!=dis+1)
                    q.push({i+1,j,dis+1}),mark[i+1][j]=dis+1;
            if(a[i+1][j+1]!=0)
                if(i+1<=m && j+1<=n && (dis+1)%a[i+1][j+1]==0 && mark[i+1][j+1]!=dis+1)
                    q.push({i+1,j+1,dis+1}),mark[i+1][j+1]=dis+1;
        }else if(i%2==0){
            if(a[i-1][j-1]!=0)
                if(i-1>0 && j-1>0 && (dis+1)%a[i-1][j-1]==0 && mark[i-1][j-1]!=dis+1)
                    q.push({i-1,j-1,dis+1}),mark[i-1][j-1]!=dis+1;
            if(a[i-1][j]!=0)
                if(i-1>0 && (dis+1)%a[i-1][j]==0 && mark[i-1][j]!=dis+1)
                    q.push({i-1,j,dis+1}),mark[i-1][j]=dis+1;
            if(a[i][j-1]!=0)
                if(j-1>0 && (dis+1)%a[i][j-1]==0 && mark[i][j-1]!=dis+1)
                    q.push({i,j-1,dis+1}),mark[i][j-1]=dis+1;
            if(a[i][j+1]!=0)
                if(j+1<=n && (dis+1)%a[i][j+1]==0 && mark[i][j+1]!=dis+1)
                    q.push({i,j+1,dis+1}),mark[i][j+1]=dis+1;
            if(a[i+1][j-1]!=0)
                if(i+1<=m && j-1>0 && (dis+1)%a[i+1][j-1]==0 && mark[i+1][j-1]!=dis+1)
                    q.push({i+1,j-1,dis+1}),mark[i+1][j-1]=dis+1;
            if(a[i+1][j]!=0)
                if(i+1<=m && (dis+1)%a[i+1][j]==0 && mark[i+1][j]!=dis+1)
                    q.push({i+1,j,dis+1}),mark[i+1][j]=dis+1;
        }
    }
    return 0;
}
/*
5
4
1 1 3 8
0 1 1 0
1 6 5 7
1 3 2 3
2 5 2 0
*/
