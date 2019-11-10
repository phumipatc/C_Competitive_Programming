/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[31];
map<int,int> m[2];
int n,w,chk[2],res[50500],val[50500];
void permute(int type,int idx,int now,int value){
    if(now>w)   return ;
    if(idx==chk[type]){
        m[type][now]=max(value,m[type][now]);
        return ;
    }
    permute(type,idx+1,now+a[idx].first,value+a[idx].second);
    permute(type,idx+1,now,value);
}
int main(){
    int t,ans;
    scanf("%d",&t);
    while(t--){
        ans=0;
        m[0].clear();
        m[1].clear();
        scanf("%d %d",&n,&w);
        chk[0]=n/2,chk[1]=n;
        for(int i=0;i<n;i++)
            scanf("%d %d",&a[i].first,&a[i].second);
        permute(0,0,0,0);
        permute(1,n/2,0,0);
        int i=0;
        for(auto it=m[0].begin();it!=m[0].end();++it,i++){
            res[i]=it->first;
            val[i]=it->second;
            if(i>0)
                val[i]=max(val[i],val[i-1]);
        }
        for(auto it=m[1].begin();it!=m[1].end();++it){
            int idx=upper_bound(res,res+m[0].size(),w-(it->first))-res;
            idx--;
            if(idx>=0 && res[idx]<=w-(it->first))
                ans=max(ans,(it->second)+val[idx]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
