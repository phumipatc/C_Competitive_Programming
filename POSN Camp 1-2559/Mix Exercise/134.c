/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int mic[1010][1010];
int main()
{
    int r,i,c,j,num,q,k,l;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&num);
            mic[i][j]=mic[i][j-1]+mic[i-1][j]-mic[i-1][j-1]+num;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&i,&j,&k,&l);
        i++,j++,k++,l++;
        printf("%d\n",mic[k][l]-mic[k][j-1]-mic[i-1][l]+mic[i-1][j-1]);
    }
return 0;
}
