/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int l,r,num;
    bool operator < (const A&o) const{
        if(l!=o.l)  return l<o.l;
        else        return r>o.r;
    }
};
A a[200010];
struct B{
    int r,num;
    bool operator < (const B&o) const{
        if(r!=o.r)  return r<o.r;
        else        return num<o.num;
    }
};
set<B > sett;
set<B > ::iterator it;
int ans[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,k,countt = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i].l >> a[i].r,a[i].num = i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        // printf("%d %d %d\n",a[i].l,a[i].r,a[i].num);
        it = sett.begin();
        while(!sett.empty() && it->r<a[i].l){
            // printf("del:%d\n",it->num);
            sett.erase(it);
            it = sett.begin();
        }
        sett.insert({a[i].r,a[i].num});
        // printf("%d\n",sett.size());
        while(sett.size()>k){
            it = sett.end();
            it--;
            // printf("%d\n",it->num);
            ans[it->num] = 1;
            sett.erase(it);
        }
    }
    for(int i=1;i<=n;i++)
        countt+=ans[i];
    cout << countt << "\n";
    for(int i=1;i<=n;i++){
        if(ans[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}