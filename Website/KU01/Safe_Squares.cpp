/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 25621
using namespace std;
typedef long long LL;
struct A{
    int x,y;
};
A a[1010];
bool cmpx(A a,A b){
    bool sw = false;
    if(a.x<b.x)         return !sw;
    else if(a.x>b.x)    return sw;
    else if(a.y<b.y)    return !sw;
    else                return sw;
}
bool cmpy(A a,A b){
    bool sw = false;
    if(a.y<b.y)         return !sw;
    else if(a.y>b.y)    return sw;
    else if(a.x<b.x)    return !sw;
    else                return sw;
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,k,ans,countt = 0;
    cin >> n >> m >> k;
    for(int i=1;i<=k;i++)
        cin >> a[i].x >> a[i].y;
    sort(a+1,a+k+1,cmpx);
    ans = ((n%MOD)*(m%MOD))%MOD;
    for(int i=1;i<=k;i++){
        if(a[i].x == a[i+1].x)  continue;
		countt++;
		ans-=m;
		ans%=MOD,ans+=MOD,ans%=MOD;
    }
	// cout << ans << "\n";
	sort(a+1,a+k+1,cmpy);
	for(int i=1;i<=k;i++){
		if(a[i].y == a[i+1].y)	continue;
		ans-=n-countt;
		ans%=MOD,ans+=MOD,ans%=MOD;
	}
	cout << ans << "\n";
    return 0;
}
/*
4 5 3
1 2
3 5
3 4
*/