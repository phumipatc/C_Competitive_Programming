/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a+b+c!=100){
        printf("BUG\n");
        return 0;
    }else{
        if(a>b && a>c)
            printf("PAPER\n");
        else if(b>a && b>c)
            printf("SCISSORS\n");
        else if(c>a && c>b)
            printf("ROCK\n");
        else if(a==b || a==c || b==c)
            printf("I DON'T KNOW");
    }
return 0;
}
