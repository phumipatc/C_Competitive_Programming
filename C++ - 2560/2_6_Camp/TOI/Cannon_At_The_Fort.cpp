/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    int n,m,k,l,ans,jump,num,idx,idx2;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(k--){
        ans = jump = 0;
        for(int i=0;i<m;i++){
            scanf("%d",&num);
            idx = lower_bound(a+jump,a+n,num-l)-a;
            idx2 = upper_bound(a+jump,a+n,num+l)-a;
            jump = idx2;
            ans+=idx2-idx;
        }
        printf("%d\n",ans);
    }
    return 0;
}
