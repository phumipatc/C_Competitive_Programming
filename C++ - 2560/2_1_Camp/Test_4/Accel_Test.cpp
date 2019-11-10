/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,value;
    bool operator < (const A&o) const{
        return value<o.value;
    }
};
struct B{
    int u,v,po;
    bool operator < (const B&o) const{
        return po>o.po;
    }
};
B now;
A x[100100],y[100100],z[100100];
priority_queue<B > heap;
int p[100100];
int findroot(int n){
    if(p[n]==n) return n;
    return p[n]=findroot(p[n]);
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&x[i].value,&y[i].value,&z[i].value),p[i]=i;
        x[i].num=y[i].num=z[i].num=i;
    }
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    sort(z+1,z+n+1);
    for(i=1;i<n;i++){
        now.u=x[i].num;
        now.v=x[i+1].num;
        now.po=abs(x[i].value-x[i+1].value);
        heap.push(now);
        now.u=y[i].num;
        now.v=y[i+1].num;
        now.po=abs(y[i].value-y[i+1].value);
        heap.push(now);
        now.u=z[i].num;
        now.v=z[i+1].num;
        now.po=abs(z[i].value-z[i+1].value);
        heap.push(now);
    }
    int ans=0;
    while(!heap.empty()){
        now=heap.top();
        heap.pop();
        int ru=findroot(now.u),rv=findroot(now.v);
        if(ru!=rv){
            p[ru]=rv;
            ans+=now.po;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3
-3 -3 -3
1 5 10
7 8 2
*/
