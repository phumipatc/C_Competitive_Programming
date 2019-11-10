/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1010][1010],mark[70][70],dic[4]= {-1,1,0,0},dir[4]= {0,0,1,-1};
struct A
{
    int i,j,area;
};
char table[200][200];
A d[8100];
void dfs(int i,int j)
{
    if(mark[i][j])
        return;
    mark[i][j]=1;
    for(int k=0; k<4; k++){
        int nowi=i+dir[k],nowj=j+dic[k];
        if(table[nowi][nowj]=='P'&&mark[nowi][nowj]==0)
            dfs(nowi,nowj);
    }
}
int main()
{
    int r,c,i,j,ans=-1,next=0,countt=0,minn=1e9,k,nowi,nowj,st,en;
    scanf("%d %d",&r,&c);
    for(i=1; i<=c; i++){
        for(j=1; j<=r; j++){
            scanf(" %c",&table[i][j]);
            if(table[i][j]=='T')
                mic[i][j]=0;
            else{
                mic[i][j]=min(mic[i-1][j-1],min(mic[i][j-1],mic[i-1][j]))+1;
                if(mic[i][j]==ans){
                    d[next].i=i,d[next].j=j,d[next].area=mic[i][j];
                    next++;
                    nowi=i,nowj=j;
                }
                if(mic[i][j]>ans){
                    d[0].i=i,d[0].j=j,d[0].area=mic[i][j];
                    next=1;
                    ans=mic[i][j];
                }
            }
        }
    }
    for(k=0; k<next; k++){
        for(i=d[k].i,countt=0; i>d[k].i-d[k].area; i--){
            for(j=d[k].j; j>d[k].j-d[k].area; j--){
                if(mark[i][j]==0&&table[i][j]=='P'){
                    countt++;
                    dfs(i,j);
                }
            }
        }
        memset(mark,0,sizeof mark);
        minn=min(countt,minn);
    }
    if(ans==-1){
        printf("0 ");
    }
    else
        printf("%d ",ans*ans);
    if(minn==1e9){
        printf("0\n");
    }
    else
        printf("%d\n",minn);
    return 0;
}
/*
8 6
SSSSSSSS
SSSSSSSS
SPPSSSSS
SSSPSSSS
SSSSSTTS
PSSSSTSS
2 2
TT
TT
6 5
TSSSSS
TTSSSS
SSSPSS
SSPPPS
TSSPST
11 5
SSSSSTSSSSS
SSPSSTSSPSS
SPPPSTSSSSS
SSPSSTSSPSS
SSSSSTSSSSS
2 2
TT
TT
*/

