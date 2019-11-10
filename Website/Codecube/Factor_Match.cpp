/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
struct A{
    int idx,v;
};
A now;
queue< A> que;
int a[1000100],b[1000100],f[100100];
int main(){
    int n,m,ans = 0;
    f[1] = 1;
    for(int i=2;i<=100000;i++){
        for(int j=1;j<sqrt(i);j++){
            if(i%j!=0)  continue;
            f[i]+=2;
        }
        if(sqrt(i) == (int)sqrt(i))
            f[i]++;
    }
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin  >> a[i];
    for(int i=1;i<=m;i++)
        cin >> b[i];
    for(int i=1;i<=n;i++){
        if(f[a[i]]!=f[b[1]])    continue;
        que.push({i ,1});
        ans = 1;
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        printf("%d %d\n",now.idx,now.v);
        if(now.idx>n || now.v == m || f[a[now.idx]]!=f[b[now.idx]]){
            ans = max(ans,now.v);
            continue;
        }
        que.push({now.idx+1,now.v+1});
    }
    cout << ans << endl;
	return 0;
}
