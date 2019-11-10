/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define hashsize 10000019
#define MOD 99999989
using namespace std;
long long hashh[hashsize+10],book[5010];
long long countt[hashsize+10];
int main(){
    long long a,b,n,m,temp,h,num,ans = 0;
    scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
    for(long long i=1;i<=a;i++)
        scanf("%lld",&book[i]);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp);
        for(long long j=0;j<m;j++){
            num = ((temp+((((j*j)%MOD)*j)%MOD))%MOD)+1;
            h = num%hashsize;
            while(hashh[h]){
                if(hashh[h] == num) break;
                h++;
                h%=hashsize;
            }
            hashh[h] = num;
            countt[h]++;
        }
    }
    for(long long i=1;i<=a;i++){
        for(long long j=0;j<b;j++){
            num = ((book[i]+((j*j)%MOD))%MOD)+1;
            h = num%hashsize;
            while(hashh[h]){
                if(hashh[h] == num){
                    ans+=countt[h];
                    countt[h] = 0;
                    break;
                }
                h++;
                h%=hashsize;
            }
        }
    }
    printf("%lld\n",ans);
	return 0;
}
