/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int a,k;
    char b[100];
    scanf("%d %d",&a,&k);
    sprintf(b,"%.0lf",a/pow(10,k));
    printf("%.0lf\n",atoi(b)*pow(10,k));
return 0;
}
