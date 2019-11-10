/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    FILE *f1,*f2;
    char str[50],str2[50];
    int a;
    f1=fopen("1.txt","r");
    fgets(str,50,f1);
    printf("%s\n",str);
    fscanf(f1,"%d %s",&a,str2);
    printf("%d %s\n",a,str2);
    return 0;
}
