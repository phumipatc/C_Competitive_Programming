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
    int value;
    scanf("%d",&value);
    switch(value%2){
        case 0:printf("Even Integer\n");    break;
        case 1:printf("Odd Integer\n");     break;
    }
    return 0;
}
