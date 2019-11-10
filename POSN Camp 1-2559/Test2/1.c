/*
    TASK:
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int find(int a,int b){
    if(a>b){
        if(a%b==0){
            return b;
        }else{
            return find(a%b,b);
        }
    }else{
        if(b%a==0)
            return a;
        else
            return find(a,b%a);
    }
}
int main()
{
    int a,b,c,i,j,x;
    scanf("%d %d %d",&a,&b,&c);
    if(a<b)
        x = find(b,a);
    else
        x = find(a,b);
    if(c%x==0)
        printf("Yes");
    else
        printf("No");

        return 0;
}
