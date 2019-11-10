/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define hashsize 10000019
#define MOD 99999989
using namespace std;
long long hashh[hashsize+10],page[5010],num[hashsize+10];
int main(){
    long long a,b,n,m,temp,p,ha,jump;
    scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
    for(long long i=1;i<=a;i++)
        scanf("%lld",&page[i]);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp);
        for(long long j=0;j<m;j++){
            p = ((temp+((((j*j)%MOD)*j)%MOD))%MOD)+1;
            ha = p%hashsize;
            jump = 1;
            while(hashh[ha]){
                if(hashh[ha] == p){
                    num[ha]++;
                    break;
                }
                ha = (p+(jump*jump)%hashsize)%hashsize;
                jump++;
            }
            hashh[ha] = p;
            if(num[ha] == 0)    num[ha] = 1;
//            printf("%lld : %lld %lld\n",ha,p,num[ha]);
        }
    }
//    cout << endl;
    long long countt = 0;
    for(long long i=1;i<=a;i++){
        for(long long j=0;j<b;j++){
            p = ((page[i]+((j*j)%MOD))%MOD)+1;
            ha = p%hashsize;
//            cout << p << endl;
            jump = 1;
            while(hashh[ha]){
                if(p == hashh[ha]){
                    countt+=num[ha];
                    break;
                }
                ha = (p+(jump*jump)%hashsize)%hashsize;
                jump++;
            }
        }
    }
    printf("%lld\n",countt);
	return 0;
}
