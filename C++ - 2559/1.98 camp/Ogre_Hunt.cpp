/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,dig=1,num=2;
    scanf("%d",&t);
    while(1){
        if(t<=num)
            break;
        t-=num;
        dig++;
        num*=2;
    }
    int i;
    t--;
    for(i=0;i<dig;i++){
        if(t/(1<<(dig-i-1))==0)
            printf("4");
        else
            printf("7");
        t%=(1<<(dig-i-1));
    }
    printf("\n");
return 0;
}
