/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
int a[10000010];
int four[10000010];
int main()
{
    int i,n,mod,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&four[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&mod);
        if(a[four[i]]==0){
            sum++,a[four[i]]=1;
        }else{
            sum--,a[four[i]]=0;
        }
        if(a[mod]==0){
            sum++,a[mod]=1;
        }else{
            sum--,a[mod]=0;
        }
            if(sum==0){
                printf("%d\n",i+1);
                return 0;
            }
    }
return 0;
}
/*
10
3 5 7 1 2 4 6 8 9 10
1 2 3 4 7 5 6 8 9 10
*/
