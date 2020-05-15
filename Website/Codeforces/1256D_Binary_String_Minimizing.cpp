/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[1000010];
int main(){
    LL q,n,k,countt;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        for(int i=1;i<=n;i++)
            scanf(" %c",&a[i]);
        countt = 0;
        for(int i=1;i<=n;i++){
            if(k == 0)  break;
            if(a[i] == '1'){
                countt++;
                continue;
            }
            if(k>=countt){
                k-=countt;
                a[i] = '1';
                a[i-countt] = '0';
            }else{
                a[i] = '1';
                a[i-k] = '0';
                k = 0;
            }
        }
        for(int i=1;i<=n;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}