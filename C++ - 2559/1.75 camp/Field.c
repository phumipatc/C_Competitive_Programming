/*
TASK: Field
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <string.h>
int a[110][110],b[110][110];
int main(){
    int r,c,i,j,k,x,y;
    scanf("%d %d %d",&c,&r,&k);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    while(k--){
        scanf("%d %d",&y,&x);
        x--,y--;
        memset(b,0,sizeof b);
        b[x][y]=1;
        while(1){
            if(a[x][y]==1)  x--;
            else if(a[x][y]==2)  y++;
            else if(a[x][y]==3)  x++;
            else if(a[x][y]==4)  y--;
            if(x==-1){ printf("N\n"); break; }
            else if(y==-1){ printf("W\n"); break; }
            else if(x==r){ printf("S\n"); break; }
            else if(y==c){ printf("E\n"); break; }
            else if(b[x][y]==1){ printf("NO\n"); break;}
            b[x][y]=1;
        }
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
