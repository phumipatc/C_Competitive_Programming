/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define prime 600011
using namespace std;
char a[300010];
long long p[12],hashh[prime+10],countt[prime+10];
int main(){
    long long q,k,sum,len,temp,ans,pos;
    scanf("%lld",&q);
    p[0] = 1ll;
    for(int i=1;i<=10;i++)
        p[i] = p[i-1]*29ll;
    while(q--){
        scanf("%lld %s",&k,a+1);
        len = strlen(a+1),sum = ans = 0;
        for(long long i=1;i<=len;i++){
            sum*=p[1];
            sum+=a[i]-'a'+1ll;
            if(i>=k){
                temp = (sum<<1)%prime;
                while(hashh[temp]){
                    if(hashh[temp] == sum){
                        countt[temp]++;
                        break;
                    }
                    temp++;
                    temp%=prime;
                }
                hashh[temp] = sum;
                if(countt[temp] == 0)
                    countt[temp]++;
                sum-=(a[i-k+1]-'a'+1ll)*p[k-1];
            }
        }
        sum = 0;
        for(long long i=1;i<=len;i++){
            sum*=p[1];
            sum+=a[i]-'a'+1ll;
            if(i>=k){
                temp = (sum<<1)%prime;
                while(hashh[temp]){
                    if(hashh[temp] == sum)  break;
                    temp++;
                    temp%=prime;
                }
                if(ans<countt[temp]){
                    ans = countt[temp];
                    pos = i;
                }
                sum-=(a[i-k+1]-'a'+1ll)*p[k-1];
            }
        }
        for(long long i=pos-k+1;i<=pos;i++)
            printf("%c",a[i]);
        printf("\n");
        memset(hashh,0,sizeof hashh);
        memset(countt,0,sizeof countt);
    }
	return 0;
}
