/*
    TASK: Food
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
int n,r,k,count,a[20],b[20],f[20];
void play(int state){
    int i,j;
    if(state==n){
            int ch=0;
            for(i=0;i<r;i++)
                if(f[i]==b[0])
                    ch=1;
            if(ch==0){
            for(i=0;i<n;i++)
                printf("%d ",b[i]);
            printf("\n");

            }
    }else{
            for(i=0;i<n;i++){
                if(a[i]!=-1){
                    a[i]=-1;
                    b[state]=i+1;
                    play(state+1);
                    a[i]=0;
                }
            }

    }




    }
int main()
{   int i;
    scanf("%d %d",&n,&r);
    for(i=0;i<r;i++)
        scanf("%d",&f[i]);
    play(0);

   return 0;
}
