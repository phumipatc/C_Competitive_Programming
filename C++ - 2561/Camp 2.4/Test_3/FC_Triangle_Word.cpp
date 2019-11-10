/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1000010];
long long qs[1000010][30];
int main(){
    long long n,q,a,len,last,ans,round,left;
    char b;
    scanf("%lld %s %lld",&n,str+1,&q);
    len = strlen(str+1);
    for(int i=1;i<=len;i++){
        qs[i][str[i]-'A']++;
        for(int j=0;j<26;j++)
            qs[i][j]+=qs[i-1][j];
    }
    while(q--){
        scanf("%lld %c",&a,&b);
        ans = 0;
        if((a-1)%2) last = ( ((a/2)%len) * ((a-1)%len) ) %len;
        else        last = ( (a%len) * (((a-1)/2)%len) ) %len;
		left = a;
		ans+= qs[len][b-'A'] - qs[last][b-'A'];
		left -= (len - last);
		if(left < 0) ans -= qs[len][b-'A'] - qs[last + a][b-'A'],left = 0;
		round = left/len;
		left%=len;
		ans+=qs[len][b-'A']*round;
		ans+=qs[left][b-'A'];
        printf("%lld\n",ans);
    }
	return 0;
}