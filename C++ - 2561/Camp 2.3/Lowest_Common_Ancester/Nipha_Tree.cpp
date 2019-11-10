/*
	Author  : Phumipat C.
	School  : RYW
	language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k,q,u,v,lu,lv,temp,countt;
	scanf("%lld %lld %lld",&n,&k,&q);
	while(q--){
		scanf("%lld %lld",&u,&v);
		if(k == 1){
			printf("%lld\n",abs(v-u));
			continue;
		}
		lu = lv = 1;
		countt = k,temp = 1;
        while(temp<u){
			lu++;
			temp+=countt;
			countt*=k;
		}
		countt = k,temp = 1;
        while(temp<v){
			lv++;
			temp+=countt;
			countt*=k;
		}
		countt = 0;
        while(lu<lv){
            countt++;
            v = (v+k-2)/k;
            lv--;
        }
        while(lv<lu){
            countt++;
            u = (u+k-2)/k;
            lu--;
        }
        while(u!=v){
            countt+=2;
            u = (u+k-2)/k;
            v = (v+k-2)/k;
        }
        printf("%lld\n",countt);
	}	
	return 0;
}
