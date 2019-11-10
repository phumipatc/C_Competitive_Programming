/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int time,sec,min,hrs,day,month,year;
void print();
int main(){
    scanf("%d",&time);
    sec=time%60;
    time/=60;
    min=time%60;
    time/=60;
    hrs=time%24;
    time/=24;
    day=time%30;
    time/=30;
    month=time%12;
    time/=12;
    year=time;
    print();
return 0;
}
void print(){
    printf("%d",year);
    if(year>1)
        printf("Years ");
    else
        printf("Year ");
    printf("%d",month);
    if(month>1)
        printf("Months ");
    else
        printf("Month ");
    printf("%d",day);
    if(day>1)
        printf("Days ");
    else
        printf("Day ");
    printf("%d",hrs);
    if(hrs>1)
        printf("Hours ");
    else
        printf("Hour ");
    printf("%d",min);
    if(min>1)
        printf("Minutes ");
    else
        printf("Minute ");
    printf("%d",sec);
    if(sec>1)
        printf("Seconds ");
    else
        printf("Second ");
}
