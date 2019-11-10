/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int i,j,k,n;
    for(i=0;i<=100;i+=6)
        for(j=0;j<=100;j+=9)
            for(k=0;k<=100;k+=20)
                a[i+j+k]=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(a[i])
            printf("%d\n",i);
    }
    if(n<6)
        printf("no\n");
    return 0;
}
