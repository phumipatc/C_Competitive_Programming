/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[1200];
int main()
{
    int q,len,i,j,count;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len = strlen(a);
        for(i=0;i<len;i=j){
            for(j=i+1,count=1;j<len;j++){
                if(a[i]==a[j])
                    count++;
                else
                    break;
            }
                printf("%d%c",count,a[i]);
        }
    }
return 0;
}
