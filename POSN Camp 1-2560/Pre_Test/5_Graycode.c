/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int n,b[15];
void binary(int state){
    int i;
    if(state==n){
        for(i=0;i<state;i++){
            if(i==0)    printf("%d",b[i]);
            else        printf("%d",(b[i]+b[i-1])%2);
        }
        printf("\n");
        return ;
    }
    b[state]=0;
    binary(state+1);
    b[state]=1;
    binary(state+1);
}
int main()
{
    int q,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        binary(0);
    }
    return 0;
}
