/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],mark[1000100],idx,countt,ans,ch;
int build(int l,int r,int now){
    if(l==r){
        mark[now]=1;
        return mark[now];
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    mark[now]=mark[now*2]+mark[(now*2)+1];
    return mark[now];
}
int divide(int l,int r,int now,int idx){
    if(l==r){
        printf("%d\n",a[l]);
        mark[now]--;
        return -1;
    }
    int x=0;
    int mid=(l+r)/2;
    if(idx<=mark[now*2])
        x=divide(l,mid,now*2,idx);
    else
        x=divide(mid+1,r,(now*2)+1,idx-mark[now*2]);
    mark[now]+=x;
    return x;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)   scanf("%d",&a[i]);
    build(1,n,1);
    for(i=1;i<=n;i++){
        scanf("%d",&idx);
        divide(1,n,1,idx);
    }
    return 0;
}
/*
5
50 40 30 20 10
1
4
3
1
1

5
50 40 30 20 10
5
4
1
2
1
*/
