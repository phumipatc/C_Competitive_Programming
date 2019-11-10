/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long countt[32];
char str[32];
int main(){
    countt[1] = 1;
    for(int i=2;i<=30;i++)  countt[i] = countt[i-1]*2;
    long long q,cnt,len,ans;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",str);
        len = strlen(str);
        cnt = 0,ans = 1;
        for(int i=0;i<len;i++){
            cnt++;
            if(str[i]!=str[i+1]){
                ans*=countt[cnt];
                cnt = 0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
