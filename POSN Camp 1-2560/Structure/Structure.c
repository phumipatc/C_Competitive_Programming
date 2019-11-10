/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
typedef struct{
    char name[50];
    char sex;
    int age;
    char blood[5];
    int day,month,year;
}person;
person a[2];
int main()
{
    int i;
    for(i=0;i<2;i++){
        scanf(" %s %c %d %s %d %d %d",a[i].name,&a[i].sex,&a[i].age,a[i].blood,&a[i].day,&a[i].month,&a[i].year);
        printf("Name:%s\nSex:%c\nAge:%d\nBlood Group:%s\nBirthday:%d/%d/%d\n",a[i].name,a[i].sex,a[i].age,a[i].blood,a[i].day,a[i].month,a[i].year);
    }
    return 0;
}
