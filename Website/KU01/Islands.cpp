/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010];
priority_queue<int > heap;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,k,now = 0,sum = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        if(a[i]<=0) sum+=1-a[i];
        if(a[i]>0){
            if(sum)         heap.push(-sum);
            if(a[i+1]<=0)   now++;
			sum = 0;
        }
    }
	if(sum)	heap.push(-sum);
	int ans = 0;
	while(now>k){
		ans-=heap.top();
		heap.pop();
		now--;
	}
	cout << ans << "\n";
    return 0;
}