/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int main(){
    long long q,n,m,sum,ans;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %lld",str,&m);
        if(strlen(str)>6)   n = m-1;
        else                sscanf(str,"%lld",&n);
        if(m == 1)      printf("0\n");
        else if(n == 0) printf("1\n");
        else{
            ans = 1,sum = 1;
            for(long long i=1;i<=n;i++){
                sum*=i;
                ans+=sum;
                sum%=m,ans%=m;
            }
            printf("%lld\n",ans);
        }
    }
	return 0;
}
