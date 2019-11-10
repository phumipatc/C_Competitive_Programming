/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
typedef struct{
    char name[50];
    char surname[50];
    char nick[20];
    char like;
    int age;
    double grade;
}Me;
int main()
{
    Me a;
    scanf(" %s %s %s %d %lf %c",a.name,a.surname,a.nick,&a.age,&a.grade,&a.like);
    printf("%c %.2lf %d %s %s %s",a.like,a.grade,a.age,a.nick,a.surname,a.name);
return 0;
}
