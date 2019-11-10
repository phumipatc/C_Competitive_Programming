/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int n,a[15];
void domino(int state,int now){
    int i;
    if(state>n)
        return ;
    if(state==n){
        for(i=0;i<now;i++){
            if(a[i])
                printf("--\n");
            else
                printf("||\n");
        }
        printf("E\n");
    }
    a[now]=1;
    domino(state+1,now+1);
    a[now]=0;
    domino(state+2,now+1);
}
int main()
{
    scanf("%d",&n);
    domino(0,0);
    return 0;
}
