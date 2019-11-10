#include<stdio.h>
#include<string.h>
char a[40][40];
int b[40][40];
int main(){
    int n,m,k,i,j,t,maxx,c;
    scanf("%d",&t);
    while(t--){
        maxx=0;
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf(" %c",&a[i][j]);
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++)
                if(a[i][j]=='#')
                    b[i][j]=1;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                b[i][j]+=b[i][j-1]+b[i-1][j]-b[i-1][j-1];
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(i>j)
                    c=j;
                else
                    c=i;
                for(k=c;k>=1;k--){
                    if(b[i][j]-b[i-k][j]-b[i][j-k]+b[i-k][j-k]==1){
                        if(maxx<k){
                            maxx=k;
                        }
                    }
                }
            }
        }
        printf("%d\n",maxx);
    }

}
