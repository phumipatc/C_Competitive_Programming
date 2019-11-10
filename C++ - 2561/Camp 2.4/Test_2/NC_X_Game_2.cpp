/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[25],b[25],dp[1050000],nextt[1050000];
int n,ans = 1e9;
void change(int i,int j){
	a[i-1]^=(1<<j);
	a[i]^=(1<<j);
	a[i]^=(1<<(j-1));
	a[i]^=(1<<(j+1));
	a[i+1]^=(1<<j);
}
void gen(int now,int state){
	if(now == n){
		dp[state] = __builtin_popcount(state);
		for(int i=0;i<n;i++){
			if(state & (1<<i)){
				nextt[state]^=(1<<(i-1));
				nextt[state]^=(1<<i);
				nextt[state]^=(1<<(i+1));
			}
		}
		return ;
	}
	gen(now+1,state|(1<<now));
	gen(now+1,state);
}
void permute(int now){
    if(now == n){
		int sum = dp[a[0]];
		for(int i=0;i<n;i++)
			b[i] = a[i];
		b[1]^=nextt[b[0]];
		b[2]^=b[0];
		for(int i=1;i<n-1;i++){
			sum+=dp[b[i]];
			b[i+1]^=nextt[b[i]];
			b[i+2]^=b[i];
		}
		if(!b[n-1])	ans = min(ans,sum);

		sum = n-dp[a[0]];
		for(int i=0;i<n;i++)
			b[i] = a[i];
		b[1]^=(!nextt[b[0]]);
		b[2]^=(!b[0]);
		for(int i=1;i<n-1;i++){
			sum+=n-dp[b[i]];
			b[i+1]^=(!nextt[b[i]]);
			b[i+2]^=(!b[i]);
		}
		if(b[n-1] == (1<<n)-1)	ans = min(ans,sum);
        return ;
    }
    permute(now+1);
    change(0,now);
    permute(now+1);
    change(0,now);
}
int main(){
    char temp;
    scanf("%d",&n);
	gen(0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&temp);
            if(temp == 'b') a[i]|=(1<<j);
        }
    }
    permute(1);
    if(ans == 1e9)  printf("Impossible\n");
    else            printf("%d\n",ans);
	return 0;
}
