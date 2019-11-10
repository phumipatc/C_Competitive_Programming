#include<stdio.h>
int a[1200][1200];
int main()
{
    int q,n,m,i,j,x,y;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&x,&y);
        if(x>n || y>m){
            printf("-1\n");
            return 0;
        }
        x--,y--;
        int maxx=0;
        for(i=0;i<n;i++){
            if(a[i][y]>maxx)
                maxx=a[i][y];
        }
        for(j=0;j<m;j++){
            if(a[x][j]>maxx)
                maxx=a[x][j];
        }
        printf("%d\n",maxx);
    }
    return 0;
}
