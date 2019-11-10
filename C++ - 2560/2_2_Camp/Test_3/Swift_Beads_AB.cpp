/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dpa[1000100],dpb[1000100];
char str[1000100];
int main(){
    int n;
    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;i++){
        if(str[i]=='A'){
            dpa[i]=dpa[i-1];
            dpb[i]=min(dpa[i-1],dpb[i-1])+1;
        }else{
            dpb[i]=dpb[i-1];
            dpa[i]=min(dpa[i-1],dpb[i-1])+1;
        }
    }
    printf("%d\n",dpa[n]);
    return 0;
}
