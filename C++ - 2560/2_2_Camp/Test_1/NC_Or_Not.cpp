/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
int mic[1000100];
char a[1000100];
int main(){
    int n,i,sum=0,countt=0,last,ans=0;
    scanf("%d",&n);
    scanf(" %s",a+1);
    for(i=1;i<=n;i++){
        if(a[i]=='0') sum++;
        else          sum--;
        mic[countt++]=sum;
    }
    mic[countt++]=0;
    sort(mic,mic+countt);
    last=0;
    for(i=1;i<countt;i++){
        if(mic[i]!=mic[i-1]){
            ans+=(i-last)*(i-last-1)/2;
            ans%=MOD;
            last=i;
        }
    }
    ans+=(countt-last)*(countt-last-1)/2;
    printf("%d\n",ans%MOD);
    return 0;
}
