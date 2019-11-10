/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int mark[100][100],dis[5][5];
void dfs(int i,int j,int value){
    mark[i][j] = value;
    if(a[i+1][j] == 'X' && mark[i+1][j] == 0)
        dfs(i+1,j,value);
    if(a[i-1][j] == 'X' && mark[i-1][j] == 0)
        dfs(i-1,j,value);
    if(a[i][j+1] == 'X' && mark[i][j+1] == 0)
        dfs(i,j+1,value);
    if(a[i][j-1] == 'X' && mark[i][j-1] == 0)
        dfs(i,j-1,value);
}
int main(){
    int r,c,i,j,k = 1,l,dis1,dis2,dis3,ans;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        scanf(" %s",a[i]+1);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            if(a[i][j] == 'X' && mark[i][j] == 0)
                dfs(i,j,k),k++;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            dis[i][j] = 1e9;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(mark[i][j] == 1){
                for(k=1;k<=r;k++){
                    for(l=1;l<=c;l++){
                        if(mark[k][l] == 2)
                            dis[1][2] = dis[2][1] = min(dis[1][2],abs(k-i)+abs(l-j)-1);
                        else if(mark[k][l] == 3)
                            dis[1][3] = dis[3][1] = min(dis[1][3],abs(k-i)+abs(l-j)-1);
                    }
                }
            }else if(mark[i][j] == 2){
                for(k=1;k<=r;k++){
                    for(l=1;l<=c;l++){
                        if(mark[k][l] == 3)
                            dis[2][3] = dis[3][2]=min(dis[2][3],abs(k-i)+abs(l-j)-1);
                    }
                }
            }
        }
    }
    ans = dis[1][2]+dis[1][3];
    ans = min(ans,dis[1][2]+dis[2][3]);
    ans = min(ans,dis[1][3]+dis[2][3]);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            dis1 = dis2 = dis3 = 1e9;
            for(k=1;k<=r;k++){
                for(l=1;l<=c;l++){
                    if(mark[k][l] == 1)
                        dis1 = min(dis1,abs(k-i)+abs(l-j));
                    else if(mark[k][l] == 2)
                        dis2 = min(dis2,abs(k-i)+abs(l-j));
                    else if(mark[k][l] == 3)
                        dis3 = min(dis3,abs(k-i)+abs(l-j));
                }
            }
            ans = min(ans,dis1+dis2+dis3-2);
        }
    }
    printf("%d\n",ans);
    return 0;
}
