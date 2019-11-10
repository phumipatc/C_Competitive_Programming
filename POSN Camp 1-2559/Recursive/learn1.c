/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
double findtax(double salary){
    return salary*0.07;
}
double savingmoney(double salary){
    int year;
    scanf("%d",&year);
    return salary*year;
}
int main()
{
    int menu,salary;
    while(1){
        scanf("%d",&menu);
        if(menu==3){
            break;
        }
        scanf("%d",&salary);
        if(menu==1){
            printf("Tax : %.2lf\n",findtax(salary));
        }else if(menu==2){
            printf("Total : %.2lf\n",savingmoney(salary));
        }
    }
return 0;
}
