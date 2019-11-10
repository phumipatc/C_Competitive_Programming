/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int p[1010];
int find_root(int n){
    if(p[n] == n)   return  n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int n,ans = 0,ru,rv,num;
    cin >> n;
    for(int i=1;i<=n+1;i++)   p[i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> num;
            if(j<=i)    continue;
            heap.push({i,j,num});
        }
    }
    for(int i=1;i<=n;i++){
        cin >> num;
        heap.push({i,n+1,num});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        p[ru] = rv;
        ans+=now.w;
    }
    cout << ans << endl;
	return 0;
}
