#include<bits/stdc++.h>
using namespace std;
int p[15][200005];
int ans[14][200005];
int a[200005];
int b[200005];
int c[15][200005];
int num[15];
int main()
{
    int n,m,i,j,k,d = 0,ch,countt;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1,j=1;i<=m;i++,j++){
        if(b[i] == 1){
            j = 0;
            countt++;
            continue ;
        }
        c[countt][j] = b[i];
        num[countt]++;
    }
    for(j=0;j<=countt;j++){
        k = 0;
        for(i=2;i<=num[j];i++){
            while(k && c[j][k+1]!=c[j][i])  k = p[j][k];
            if(c[j][k+1] == c[j][i])        k++;
            p[j][i] = k;
            //printf("%d ",c[j][i]);
        }
        //printf("\n");
    }
    for(j=0;j<=countt;j++){
        k = 0;
        for(i=1;i<=n;i++){
            while(k && a[i]!=c[j][k+1]) k = p[j][k];
            if(a[i] == c[j][k+1])       k++;
            ans[j][i] = (k == num[j]);
            //printf("%d ",ans[j][i]);
        }
        //printf("\n");
    }
    for(i=1;i<=countt;i++)
        num[i]+=num[i-1]+1;
    for(i=1;i+m-1<=n;i++){
        ch=1;
        for(j=0;j<=countt;j++)
            if(ans[j][i+num[j]-1] == 0)
                ch = 0;
        d+=ch;
        //printf(">>%d %d\n",countt,d);
    }
    printf("%d",d);
    return 0;
}
