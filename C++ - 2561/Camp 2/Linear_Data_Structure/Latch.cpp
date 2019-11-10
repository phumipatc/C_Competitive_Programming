/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
};
A now;
stack<A > st;
long long a[1010][1010],countt[1010][1010];
int main(){
    long long n,m,ans = 0,fir,minn,ch;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            if(a[i][j] == a[i-1][j])
                countt[i][j] = countt[i-1][j];
            countt[i][j]++;
        }
    }
    for(long long i=1;i<=n;i++){
        fir = 1;
        for(long long j=1;j<=m;j++){
            while(!st.empty() && st.top().v>=countt[i][j])  st.pop();
            if(st.empty()){
                ans+=(j-fir+1)*countt[i][j];
            }else{
                ans+=(j-st.top().idx)*countt[i][j];
            }
            st.push({j,countt[i][j]});
            if(a[i][j]!=a[i][j+1]){
                if(!st.empty())
                while(!st.empty()){
//something
                }
                fir = j+1;
            }
            printf("%lld %lld : %lld\n",i,j,ans);
        }
        while(!st.empty()){
//something
        }
    }
    printf("%lld\n",ans);
	return 0;
}
