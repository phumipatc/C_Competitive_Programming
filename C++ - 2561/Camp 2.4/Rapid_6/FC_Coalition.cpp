/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v;
    bool operator < (const A&o) const{
        return v>o.v;
    }
};
int a[300001],qs[300001];
A b[300001];
int main(){
    int n,sum=0,res,ch;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i].v=a[i];
        sum+=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        qs[i] = b[i].v+qs[i-1];
    for(int i=1;i<=n;i++){
        int l = 1,r = n;
        while(l<r){
            int mid = (l+r)/2;
            res = qs[mid];
            if(a[i]<=b[mid].v)  res+=a[i];
            if(res>sum/2)   r = mid;
            else            l = mid+1;
        }
        if(a[i]>b[l].v)   printf("%d\n",l-1);
        else              printf("%d\n",l);
    }
    return 0;
}
