/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int k,a[200];
void sport(int state,int w,int l){
    if(w==k || l==k){
        int i;
        for(i=0;i<state;i++){
            if(a[i]==0)
                printf("W ");
            else
                printf("L ");
        }
        printf("\n");
        return ;
    }
    a[state]=0;
    sport(state+1,w+1,l);
    a[state]=1;
    sport(state+1,w,l+1);
}
int main()
{
    int w,l;
    scanf("%d %d %d",&k,&w,&l);
    sport(0,w,l);
return 0;
}
