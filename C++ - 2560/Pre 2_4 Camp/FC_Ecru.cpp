/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    char str[3005];
    bool operator < (const A&o) const{
        if(strcmp(str,o.str)<=0)    return true;
        else                        return false;
    }
};
A a[3005];
long long fact[3005];
long long countt(long long l,long long r,long long now){
    if(l==r)    return 1;
    long long i,j,ans=1,group=0,ch=1,ch2=0,num;
    while(ch){
        for(i=l;i<=r;i++){
            for(j=i;j<r && a[j].str[now]==a[j+1].str[now];j++);
            if(i==l && j==r){
                if(a[j].str[now]==0) return 1;
                break;
            }else{
                ch=0;
                if(a[i].str[now]==0){
                    ch2=1;
                    num=j-i+1;
                }else{
                    ans=(ans*countt(i,j,now+1))%MOD;
                    group++;
                }
            }
            i=j;
        }
        if(ch) now++;
    }
    if(ch2){
        for(i=num+1;i<=num+group;i++)
            ans=(ans*i)%MOD;
        return ans;
    }
    return (ans*fact[group])%MOD;
}
int main(){
    fact[0]=1;
    for(long long i=1;i<=3000;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf(" %s",&a[i].str);
    sort(a+1,a+n+1);
    printf("%lld\n",countt(1,n,0));
    return 0;
}
