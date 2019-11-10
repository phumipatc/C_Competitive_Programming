/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[5000010],str2[10000010];
int KMP[10000005];
int main(){
    int n,i,j = 0;
    scanf("%d %s",&n,str+1);
    for(i=2;i<=n;i++){
        while(j>0 && str[i]!=str[j+1])  j = KMP[j];
        if(str[i] == str[j+1])  j++;
        KMP[i] = j;
    }
    strcpy(str2+1,str+1);
    strcat(str2+1,str+1);
    j = 0;
    for(i=2;i<=n+n;i++){
        while(j>0 && str2[i]!=str[j+1]) j = KMP[j];
        if(str2[i] == str[j+1]) j++;
        if(j == n){
            printf("%d\n",i-j);
            return 0;
        }
    }
    return 0;
}
