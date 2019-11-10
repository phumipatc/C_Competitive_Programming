/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[5000100],str2[10000100];
int KMP[5000100];
int main(){
    long long n,j=0,i;
    scanf("%lld %s",&n,str+1);
    for(i=2;i<=n;i++){
        while(j>0 && str[j+1]!=str[i])  j=KMP[j];
        if(str[j+1]==str[i])    j++;
        KMP[i]=j;
    }
    strcpy(str2+1,str+1);
    strcat(str2+1,str+1);
//    printf("%s",str2+1);
    j=0;
    for(i=2;i<=2*n;i++){
        while(j>0 && str[j+1]!=str2[i])  j=KMP[j];
        if(str[j+1]==str2[i])    j++;
        if(j==n){
            printf("%lld\n",i-j);
            break;
        }
    }
    return 0;
}
