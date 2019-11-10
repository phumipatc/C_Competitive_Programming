/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,a[20];
void domino(int state,int at){
    if(state>n){
        return ;
    }
    if(state==n){
        int i;
        for(i=0;i<at;i++){
            if(a[i]==0)
                printf("--\n");
            if(a[i]==1)
                printf("||\n");
        }
        printf("E\n");
    }
    a[at]=0;
    domino(state+1,at+1);
    a[at]=1;
    domino(state+2,at+1);
}
int main()
{
    scanf("%d",&n);
    domino(0,0);
return 0;
}
