/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[300100],t[300100],r[300100];
int find_head(int x){
    if(x==h[x]) return x;
    return h[x]=find_head(h[x]);
}
int find_tail(int x){
    if(x==t[x]) return x;
    return t[x]=find_tail(t[x]);
}
int main()
{
    int n,i,j,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        h[i]=t[i]=i,r[i]=0;
    while(n-->1){
        scanf("%d %d",&a,&b);
        if(r[b]==0){
            r[b]=a;
            t[b]=t[a]=find_tail(a);
            h[a]=h[b]=find_head(b);
        }else{
            t[a]=find_tail(a),h[a]=find_head(a);
            t[b]=find_tail(b),h[b]=find_tail(b);
            r[t[a]]=r[b];
            r[b]=a;
            h[a]=h[b],t[a]=t[b];
        }
    }
    i=find_head(1);
    for(j=0;j<n-1;j++){
        printf("%d ",i);
        i=r[i];
    }
    printf("%d\n",i);
    return 0;
}
