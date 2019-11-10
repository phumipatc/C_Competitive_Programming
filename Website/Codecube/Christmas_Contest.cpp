/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int bit[30][2];
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        for(int j=0;j<27;j++){
            if(num & 1<<j)  bit[j][1]++;
            else            bit[j][0]++;
        }
    }
    scanf("%d",&n);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        for(int j=0;j<27;j++){
            if(num & (1<<j))    swap(bit[j][0],bit[j][1]);
            ans+=(long long )bit[j][1]*(1<<j);
        }
        for(int j=0;j<27;j++)
            if(num & (1<<j))    swap(bit[j][0],bit[j][1]);
    }
    printf("%lld\n",ans);
	return 0;
}