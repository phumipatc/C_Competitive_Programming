/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> st,en;
int a[1000100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        st[a[i]]=1e18;
    }
    for(int i=1;i<=n;i++){
        st[a[i]]=min(st[a[i]],i);
        en[a[i]]=max(en[a[i]],i);
    }
    sort(a+1,a+n+1);
    int now=0;
    for(int i=1;i<=n;i++){
        int dis_en=abs(en[a[i]]-i);
        int dis_st=abs(st[a[i]]-i);
        now=max(now,max(dis_st,dis_en));
        if(a[i]!=a[i+1])
            printf("%d %d\n",a[i],now),now=0;
    }
    return 0;
}
