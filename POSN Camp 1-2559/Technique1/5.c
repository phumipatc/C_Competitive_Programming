/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    if(n==1){
        printf("No");
        return 0;
    }
    for(i=2;i<=sqrt(n);i++){
        if(n%i==0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}
