/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<string.h>
char a[100100];
int main()
{
    int n,i,j,top=-1;
    char b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %c",&b);
        top++;
        a[top]=b;
        if(top>0 && a[top]==a[top-1]){
            top-=2;
        }
    }
    printf("%d\n",top+1);
    for(i=top;i>=0;i--)
        printf("%c",a[i]);
        if(top==-1)
            printf("empty");
return 0;
}
