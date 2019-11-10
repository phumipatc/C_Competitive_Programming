/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<long long > v[100010],qs[100010];
long long LIS[100010];
int main(){
    long long n,maxx = 0,temp,idx;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp);
        idx = lower_bound(LIS,LIS+maxx,temp)-LIS;
        // if(idx>0 && LIS[idx-1] == temp)	idx--;
        if(idx == 0 && i!=1)			continue;
        if(idx == maxx) 				maxx++;
		v[idx].push_back(temp);
        LIS[idx] = temp;
        if(idx == 0){
            qs[idx].push_back(1);
            continue;
        }
        long long l = 0,r = v[idx-1].size()-1;
        while(l<r){
            long long mid = (l+r)>>1;
            if(v[idx-1][mid]<temp)  r = mid;
            else                    l = mid+1;
        }
        qs[idx].push_back(qs[idx-1].back());
        if(l>0) qs[idx].back()-=qs[idx-1][l-1];
        if(qs[idx].size()>1)    qs[idx].back()+=qs[idx][qs[idx].size()-2];
        qs[idx].back()%=MOD;
        if(qs[idx].back()<0)    qs[idx].back()+=MOD;
    }
    printf("%lld\n",qs[maxx-1].back());
	return 0;
}
