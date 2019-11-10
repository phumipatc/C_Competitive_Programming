/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[13],n;
void arrange(int state,int at){
    int i;
    if(state>n)
        return ;
    if(state==n){
        for(i=0;i<at;i++)
            if(a[i]==0)
                printf("--\n");
            else
                printf("||\n");
            printf("E\n");
            return ;
    }
    a[at]=0;
    arrange(state+1,at+1);
    a[at]=1;
    arrange(state+2,at+1);
}
int main()
{
    scanf("%d",&n);
    arrange(0,0);
    return 0;
}
