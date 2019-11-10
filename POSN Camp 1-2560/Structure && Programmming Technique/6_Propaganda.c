/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int d,i,ch=1;
    scanf("%d",&d);
    for(i=2;i<=sqrt(d);i++)
        if(d%i==0)
            ch=0;
    if(d==1){
        printf("No\n");
        return 0;
    }
    printf((ch)?"Yes\n":"No\n");
    return 0;
}
