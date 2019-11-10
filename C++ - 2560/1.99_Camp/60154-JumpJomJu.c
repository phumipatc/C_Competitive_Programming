#include<bits/stdc++.h>
using namespace std;
char table[101][30003];
int scar[101][30003];
int col[10001];
int main()
{

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            scanf(" %c",&table[i][j]);
            table[i][j+m]=table[i][j];
            table[i][j+m*2]=table[i][j];
            scar[i][j]=1e6;
            scar[i][j+m]=1e6;
            scar[i][j+m*2]=1e6;
        }
    }
    for(int i = 0; i < n; i++)
    {
        int lanr=0,lanl=0;
        int ch=1;
        for(int j = 0; j < m*3;j++)
        {
            if(table[i][j]=='1'){
                lanr=0;
                ch=0;
            }
            scar[i][j]=min(scar[i][j],lanr);
            lanr++;
            if(table[i][m*3-j-1]=='1'){
                lanl=0;
                ch=0;
            }
            scar[i][m*3-j-1]=min(scar[i][m*3-j-1],lanl);
            lanl++;

        }
        if(ch)
            {
                printf("-1");
                return 0;
            }
    }
    long long int ans=1e16;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            //printf("%d ",scar[i][j+m]);
            col[j]+=scar[i][j+m];
            if(i==n-1)
            {
                ans=min(ans,(long long)col[j]);
            }
        }
        //printf("\n");
    }
    printf("%lld",ans);
    return 0;
}
