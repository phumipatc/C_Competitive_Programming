/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1024],ans[1024];
void divide(int l,int r,int now){
    int mid = (l+r)/2;
    ans[now] = a[mid];
    if(l == r)  return ;
    divide(l,mid,now*2);
    divide(mid+1,r,(now*2)+1);
}
int main(){
    int k,n = 1,row = 1,now = 0;
    cin >> k;
    for(int i=1;i<=k;i++)   n*=2;
    n--;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    divide(1,n,1);
    for(int i=1;i<=n;i++){
        now++;
        cout << ans[i] << " ";
        if(now == row){
            cout << endl;
            row*=2;
            now = 0;
        }
    }
    return 0;
}
