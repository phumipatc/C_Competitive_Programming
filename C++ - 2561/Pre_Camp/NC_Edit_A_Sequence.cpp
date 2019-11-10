/*
    TASK:
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> tree[400100];
void update(int l,int r,int idx,int now,int val){
    if(l>idx||r<idx)	return ;
    if(l == r){
		tree[now] = {val,val};
		return ;
	}
    int mid = (l+r)/2;
    update(l,mid,idx,now*2,val);
    update(mid+1,r,idx,now*2+1,val);
    tree[now].first = min(tree[now*2].first,tree[now*2+1].first);
    tree[now].second = max(tree[now*2].second,tree[now*2+1].second);
}
pair<int,int> query(int l,int r,int ll,int rr,int now){
    if(!l) l++;
    if(l>rr||r<ll||l>r)	return {1e9,0};
    if(l>=ll && r<=rr)	return tree[now];
    int mid = (l+r)/2;
    pair<int,int> le = query(l,mid,ll,rr,now*2);
    pair<int,int> ri = query(mid+1,r,ll,rr,now*2+1);
    return {min(le.first,ri.first),max(le.second,ri.second)};
}
int l[100100],r[100100],a[100100];
int main()
{
    int n,i,cnt = 0,maxx = 0,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        update(1,n,i,1,a[i]);
    }
    a[n+1] = n+1;
    for(i=1;i<=n;i++){
		cnt++;
        l[cnt] = i;
        while(a[i+1]>a[i]) i++;
        r[cnt] = i;
    }
    r[cnt] = n;
    for(i=1;i<=cnt;i++){
        if(i-1){
			sum = 0;
			if(a[l[i]]>a[l[i]-2])	sum=r[i-1]-l[i-1]+1;
			if(a[r[i-1]]<a[l[i]+1] && a[l[i]]<a[r[i-1]])
				sum+=r[i]-l[i]+1;
			maxx = max(maxx,sum);
        }
        if(a[r[i]]!=n && r[i]!=n)	maxx = max(maxx,r[i]-l[i]+2);
        if(a[l[i]]!=1 && l[i]!=1)	maxx = max(maxx,r[i]-l[i]+2);
        sum = r[i]-l[i]+1;
        if((a[r[i]+1]>a[l[i]-2]||l[i]-2<l[i-1]) && a[r[i]+1]<a[l[i]])	sum+=r[i-1]-l[i-1]+1;
        if(a[l[i]-1]>a[r[i]] && (a[l[i]-1]<a[r[i]+2]||r[i]+2>r[i+1]))	sum+=r[i+1]-l[i+1]+1;
        maxx = max(maxx,sum);
        pair<int,int> le = query(1,n,a[l[i]-1],a[l[i]+1],1);
        pair<int,int> ri = query(1,n,a[l[i]-2],a[l[i]],1);
        if(min(le.first,ri.first)<l[i-1])	maxx=max(maxx,r[i]+r[i-1]-l[i]-l[i-1]+2);
        if(max(le.second,ri.second)>r[i-1])	maxx=max(maxx,r[i]+r[i-1]-l[i]-l[i-1]+2);
    }
    printf("%d",maxx);
    return 0;
}

