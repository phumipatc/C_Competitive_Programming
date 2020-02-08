/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,num;
};
A now;
stack<A > st;
long long a[1010][1010],height[1010][1010];
int main(){
    long long n,m,ans = 0,sum;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(a[i][j] == a[i-1][j])
                height[i][j] = height[i-1][j];
            height[i][j]++;
        }
    }
    for(long long i=1;i<=n;i++){
		sum = 0;
        for(long long j=1;j<=m;j++){
			int countt = 1;
			while(!st.empty() && st.top().v>height[i][j]){
				now = st.top();
				countt+=now.num;
				sum-=now.v*now.num;
				st.pop();
			}
			st.push({height[i][j],countt});
			sum+=height[i][j]*countt;
			ans+=sum;
			if(a[i][j]!=a[i][j+1]){
				while(!st.empty())	st.pop();
				sum = 0;
			}
			// printf("%lld ",sum);
        }
		// cout << endl;
    }
	printf("%lld\n",ans);
	return 0;
}
