#include<bits/stdc++.h>
using namespace std;
int mic[1010],Q;
int recurse(int n){
    int i,sum=0,a,b;
    for(i=0;i<n;i++){
        a=(mic[i]!=-1)? mic[i]:recurse(i);
        b=(mic[n-i-1]!=-1)? mic[n-i-1]:recurse(n-i-1);
        sum+=a*b%9973;
    }
    return mic[n]=sum%9973;
}
int main()
{
    int q,n;
    memset(mic,-1,sizeof mic);
    mic[0]=mic[1]=1;
    Q=recurse(1000);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",mic[n-1]);
    }
    return 0;
}
