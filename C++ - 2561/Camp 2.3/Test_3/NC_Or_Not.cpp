/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
char a[1000010];
map<int ,int > mapp;
int main(){
    int n,sum = 0,ans = 0;
    scanf("%d %s",&n,a+1);
    mapp[0] = 1;
    for(int i=1;i<=n;i++){
        sum+=(a[i]-'0');
        ans+=mapp[sum+sum-i];
        mapp[sum+sum-i]++;
        ans%=MOD;
        mapp[sum+sum-i]%=MOD;
        // printf("%d %d\n",sum+sum-i,mapp[sum+sum-i]);
    }
    printf("%d\n",ans);
	return 0;
}
