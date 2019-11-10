/*
    TASK: Bee
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int work[50],soldier[50];
int main(){
    int i,n;
    work[0]=1;
    for(i=0;i<=24;i++){
        work[i]=work[i-1]+soldier[i-1]+1;
        soldier[i]=work[i-1];
    }
    while(1){
        scanf("%d",&n);
        if(n==-1)   break;
        printf("%d %d\n",work[n],work[n]+soldier[n]+1);
    }
    return 0;
}
