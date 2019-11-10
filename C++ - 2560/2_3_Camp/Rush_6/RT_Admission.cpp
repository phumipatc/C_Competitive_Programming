/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int main(){
    int n,a,b,c;
    scanf("%d",&n);
    while(n--){
        scanf(" %s %d %d %d",str,&a,&b,&c);
        int len=strlen(str);
        if(len%2==0)    printf("PASS\n");
        else            printf("FAIL\n");
    }
    return 0;
}
