/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[25],str2[25];
int main(){
    int n,len;
    scanf("%d",&n);
    for(int i=1;i<n+n;i++){
        scanf(" %s",str2+1);
        len=strlen(str2+1);
        for(int j=1;j<=len;j++)
            str[j]^=str2[j];
    }
    printf("%s\n",str+1);
    return 0;
}
