/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 30011
using namespace std;
struct A{
    int l,r;
};
A a[100010];
vector<int > v[200010];
int tree[200010];
void upd(int idx,int v){
    while(idx<=200003){
        tree[idx]+=v;
        tree[idx]%=MOD;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        sum%=MOD;
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,k,l,x,y,ll,rr,mid,idx,idx2;
    cin >> n >> m >> k >> l;
    for(int i=1;i<=l;i++){
        cin >> x >> y;
        v[x].push_back(n+y);
        v[n+y].push_back(x);
    }
    for(int i=1;i<=l+l;i++)
        sort(v[i].begin(),v[i].end());
    for(int i=1;i<=n;i++){
        cin >> y >> x;
        x+=n;
        idx = lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
        ll = x+y-1,rr = n+m;
        while(ll<rr){
            mid = (ll+rr)/2;
            idx2 = upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
            if((mid-x+1)-(idx2-idx)>=y) rr = mid;
            else                        ll = mid+1;
        }
        a[i] = {x,ll};
        // printf("Left: %d %d\n",x,ll);
    }
    for(int i=n+1;i<=n+m;i++){
        cin >> y >> x;
        idx = lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
        ll = x+y-1,rr = n+m;
        while(ll<rr){
            mid = (ll+rr)/2;
            idx2 = upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
            if((mid-x+1)-(idx2-idx)>=y) rr = mid;
            else                        ll = mid+1;
        }
        a[i] = {x,ll};
        // printf("Right: %d %d\n",x,ll);
    }
    upd(1,1);
    upd(n+1,-1);
    for(int i=1;i<=k;i++){
        if(i%2){
            for(int i=1;i<=n;i++){
                int val = query(i);
                upd(a[i].l,val);
                upd(a[i].r+1,-val);
                idx = lower_bound(v[i].begin(),v[i].end(),a[i].l)-v[i].begin();
                for(;idx<v[i].size() && v[i][idx]<=a[i].r;idx++)
                    upd(v[i][idx],-val),upd(v[i][idx]+1,val);
            }
            // for(int i=n+1;i<=n+m;i++)
            //     printf("%d ",query(i));
            // printf("\n");
        }else{
            if(i == 2){
                upd(1,-1);
                upd(n+1,1);
            }
            for(int i=n+1;i<=n+m;i++){
                int val = query(i);
                upd(a[i].l,val);
                upd(a[i].r+1,-val);
                idx = lower_bound(v[i].begin(),v[i].end(),a[i].l)-v[i].begin();
                for(;idx<v[i].size() && v[i][idx]<=a[i].r;idx++)
                    upd(v[i][idx],-val),upd(v[i][idx]+1,val);
            }
            // for(int i=1;i<=n;i++)
            //     printf("%d ",query(i));
            // printf("\n");
        }
    }
    int ans = 0;
    if(k%2 == 0)
        for(int i=1;i<=n;i++){
            ans+=query(i),ans%=MOD;
    }else{
        for(int i=n+1;i<=n+m;i++)
            ans+=query(i),ans%=MOD;
    }
    cout << ans << "\n";
    return 0;
}
/*
5 5 3 0
2 1
2 2
2 3
2 4
1 5
2 1
2 2
2 3
2 4
1 5
*/