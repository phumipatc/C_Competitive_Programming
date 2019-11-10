/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int ,int > mapp;
int a[500010];
int main(){
    int n,q,st,en;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int u,v;
    while(q--){
        scanf("%d %d",&u,&v);
        for(int i=u;i<=v;i++){
            mapp[a[i]]++;
        }
        int ans = 0;
        for(auto x:mapp){
            if(x.second!=2) continue;
            ans++;
        }
        printf("%d\n",ans);
        mapp.clear();
    }
	return 0;
}