/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int num[150],kk[150],ch[150];
int main()
{
    int n,min,k,i,j,ans,run=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n;i++)
        scanf("%d",&kk[i]);
    for(i=0;i<n;i++){
        for(j=0;;){
            if(num[run]!=-1){
                j++;
            }
            if(j==kk[i]+1 && num[run]!=-1) { break; }
            run++; run%=n;
        }
        ch[i%k]+=num[run];
        num[run]=-1;
    }
    for(i=0;i<k;i++){
        printf("%d\n",ch[i]);
    }

    return 0;
}
/*
5 3
3 5 2 4 1
3
5
1
2
1
*/
