/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[2000],b[2000];
int main()
{
    int i,j,n,l,count=0;
    scanf("%d %d %s",&l,&n,a);
    for(i=0;i<n-1;i++){
        scanf(" %s",b);
        for(j=0;j<l;j++){
            if(a[j]!=b[j])
                count++;
        }
        if(count>2){
            printf("%s",a);
            return 0;
        }else{
        strcpy(a,b);
        count=0;
        }
    }
    if(n==1)
        printf("%s",a);
            printf("%s",b);
return 0;
}
