/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],qs[100005],ans;
void merge_sort(long long l,long long r){
    if(l == r)  return ;
    long long mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    long long p = l,q = mid+1,k = l;
    while(p<=mid && q<=r){
        if(a[p]<=a[q])
            b[k++] = a[p++];
        else{
            ans+=((mid-p+1)*a[q])+(qs[mid]-qs[p-1]);
            b[k++] = a[q++];
        }
    }
    while(p<=mid)
        b[k++] = a[p++];
    while(q<=r)
        b[k++] = a[q++];
    for(long long i=l;i<=r;i++){
        a[i] = b[i];
        qs[i] = a[i]+qs[i-1];
    }
}
int main(){
    long long q,n,num;
    cin >> q;
    while(q--){
        ans = 0;
        cin >> n;
        for(long long i=1;i<=n;i++){
            cin >> a[i];
            qs[i] = a[i]+qs[i-1];
        }
        merge_sort(1,n);
        cout << ans << endl;
    }
    return 0;
}
