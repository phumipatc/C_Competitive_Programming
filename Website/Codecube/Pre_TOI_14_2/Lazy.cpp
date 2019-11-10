/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
vector< int> v[100005];
int a[100005];
int main(){
    int n,q,idx = 1,idx2,l,r,k;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!mapp[a[i]]) mapp[a[i]] = idx++;
        v[mapp[a[i]]].push_back(i);
    }
    while(q--){
        scanf("%d %d %d",&l,&r,&k);
        idx = lower_bound(v[mapp[k]].begin(),v[mapp[k]].end(),l)-v[mapp[k]].begin();
        idx2 = upper_bound(v[mapp[k]].begin(),v[mapp[k]].end(),r)-v[mapp[k]].begin();
        printf("%d\n",idx2-idx);
    }
    return 0;
}
