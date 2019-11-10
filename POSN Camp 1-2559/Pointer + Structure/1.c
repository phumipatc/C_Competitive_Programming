/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int *b;
    b = &a[0];
    for(;b!=&a[10];b++){
        printf("%d\t",*b);
    }
return 0;
}
