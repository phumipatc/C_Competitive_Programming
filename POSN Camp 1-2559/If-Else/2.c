/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    switch(x){
        case 1 :printf("Sunday"); break;
        case 2 :printf("Monday"); break;
        case 3 :printf("Tuesday"); break;
        case 4 :printf("Wednesday"); break;
        case 5 :printf("Thursday"); break;
        case 6 :printf("Friday"); break;
        case 7 :printf("Saturday"); break;
        default :printf("Not a day"); break;
    }
return 0;
}
