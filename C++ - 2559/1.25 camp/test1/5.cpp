/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int main()
{
    int n,k,i,x,y,chx=0,chy=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        if((x<=k && x>=0) || (x>=(-1*k) && x<=0))
            chx++;
        if((y<=k && y>=0) || (y>=(-1*k) && y<=0))
            chy++;
    }
    if(chx>=chy)
        printf("%d",chx);
    else
        printf("%d",chy);
return 0;
}
/*
3 3
1 2
3 5
5 5
*/
