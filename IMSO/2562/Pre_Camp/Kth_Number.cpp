/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n;
int arr[N],pos[N],root[N];
struct node{
    int val,left,right;
};
node st[20*N];
int total=0;
int cpy(int x){
    ++total;
    st[total] = st[x];
    return total;
}
int ask(int i,int j,int p,int l=1,int r=n){
    if(i>r || j<l)      return 0;
    if(l>=i && r<=j)    return st[p].val;
    int mid = (l+r)/2;
    int x = ask(i,j,st[p].left,l,mid);
    int y = ask(i,j,st[p].right,mid+1,r);
    return x+y;
}
int  update(int x,int p,int l=1,int r=n){
    if(x>r || x<l)  return p;
    if(l==r){
        int res = cpy(p);
        st[res].val++;
        return res;
    }
    int mid = (l+r)/2;
    int a = update(x,st[p].left,l,mid);
    int b = update(x,st[p].right,mid+1,r);
    int res = cpy(p);
    st[res].left = a;
    st[res].right = b;
    st[res].val = st[a].val + st[b].val;
    return res;
}
int main(){
    int q,a,b,k;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)   scanf("%d",&arr[i]);
    // all.resize(unique(all.begin(),all.end())-all.begin());
    st[0].val=st[0].left=st[0].right=0;
    for(int i=1;i<=n;i++)   root[i]=update(arr[i],root[i-1]);
    while(q--){
        scanf("%d %d %d",&a,&b,&k);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)/2;
            int ans = ask(1,mid,root[b])-ask(1,mid,root[a-1]);
            if(ans>=k)  r=mid;
            else        l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
/*
10 7
10 7 2 5 1 3 4 6 8 9
1 5 1
1 5 2
1 5 3
3 10 8
3 10 4
3 6 2
3 6 3
*/
