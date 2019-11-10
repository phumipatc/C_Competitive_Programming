/*
TASK: Bombyun
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
int a[2000][2000];
int main(){
    int n,m,i,j,x,y,r,p,q,count;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        a[x][y]=1;
    }
    while(m--){
        scanf("%d %d %d",&x,&y,&r);
        p=x-r;
        if(p<0)   p=0;
        q=y-r;
        if(q<0)   q=0;
        count=0;
        for(i=p;i<=x+r;i++){
            for(j=q;j<=y+r;j++){
                if(a[i][j]==1){
                    a[i][j]=0;
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
	return 0;
}
/*
2 2 2
2 2
2 1
1 1
1 2
*/
