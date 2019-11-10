/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[300][300],x[5100],y[5100],d[5100];
int main()
{
    int q,i,n,m,j,a,b,c,p,k,s,e,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==j)    mic[i][j]=0;
                else        mic[i][j]=1e9;
        while(m--){
            scanf("%d %d %d",&a,&b,&c);
            mic[a][b]=mic[b][a]=c;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    mic[i][j]=min(mic[i][j],mic[i][k]+mic[k][j]);
        scanf("%d",&p);
        for(i=0;i<p;i++)
            scanf("%d %d %d",&x[i],&y[i],&d[i]);
        for(i=1;i<=n-1;i++){
            for(j=i+1;j<=n;j++){
                ch=1;
                for(k=0;k<p;k++){
                    s=x[k],e=y[k];
                    if(min(mic[s][e],min(mic[s][i]+mic[j][e],mic[s][j]+mic[i][e]))!=d[k]){
                        ch=0;
                        break;
                    }
                }
                if(ch){
                    printf("%d %d\n",i,j);
                    goto jump;
                    break;
                }
            }
        }
        jump: ;
    }
    return 0;
}
