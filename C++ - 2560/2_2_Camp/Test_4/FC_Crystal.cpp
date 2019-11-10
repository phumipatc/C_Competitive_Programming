/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10001
using namespace std;
int mic[1100];
int main(){
    int n;
    scanf("%d",&n);
    mic[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            mic[i]+=mic[j]*mic[i-j-1];
            mic[i]%=MOD;
        }
    }
    for(int i=0;i<=20;i++)
        printf("%d ",mic[i]);
    return 0;
}
