/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define pos first
#define id second
using namespace std;
pair<int ,int > a[50010];
map<int ,int > mapp;
int main(){
    int q,n,countt,now,last,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        countt = now = 0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].pos,&a[i].id);
            mapp[a[i].id]++;
            if(mapp[a[i].id] == 1)  countt++;
        }
        sort(a+1,a+n+1);
        mapp.clear();
        last = 1,ans = 1e9;
        for(int i=1;i<=n;i++){
            mapp[a[i].id]++;
            if(mapp[a[i].id] == 1)  now++;
            while(now == countt){
                ans = min(ans,a[i].pos-a[last].pos+1);
                mapp[a[last].id]--;
                if(mapp[a[last].id] == 0)   now--;
                last++;
            }
        }
        printf("%d\n",ans);
        mapp.clear();
    }
	return 0;
}
