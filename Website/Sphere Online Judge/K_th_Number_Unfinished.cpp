/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > tree[400010],temp,space,ans;
int a[100010];
void build(int l,int r,int now){
    if(l == r){
        tree[now].push_back(a[l]);
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,now*2+1);
    int i = 0,j = 0;
    while(i<tree[now*2].size() && j<tree[now*2+1].size()){
        if(tree[now*2][i]<tree[now*2+1][j])
            tree[now].push_back(tree[now*2][i]),i++;
        else
            tree[now].push_back(tree[now*2+1][j]),j++;
    }
    while(i<tree[now*2].size())
        tree[now].push_back(tree[now*2][i]),i++;
    while(j<tree[now*2+1].size())
        tree[now].push_back(tree[now*2+1][j]),j++;
}
vector<int > query(int l,int r,int now,int ll,int rr){
    if(r<ll || l>rr)    return space;
    if(l>=ll && r<=rr)  return tree[now];
    // printf("%d %d\n",l,r);
    int mid = (l+r)/2;
    vector<int > L = query(l,mid,now*2,ll,rr);
    vector<int > R = query(mid+1,r,now*2+1,ll,rr);
    int i = 0,j = 0;
    ans.clear();
    while(i<L.size() && j<R.size()){
        if(L[i]<R[j])   ans.push_back(L[i]),i++;
        else            ans.push_back(R[j]),j++;
    }
    while(i<L.size())   ans.push_back(L[i]),i++;
    while(j<R.size())   ans.push_back(R[j]),j++;
    return ans;
}
int main(){
    int n,m,l,r,k;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    while(m--){
        scanf("%d %d %d",&l,&r,&k);
        temp = query(1,n,1,l,r);
        printf("%d\n",temp[k-1]);
    }
    return 0;
}
