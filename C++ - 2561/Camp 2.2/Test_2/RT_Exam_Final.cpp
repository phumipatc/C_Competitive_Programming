/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],need[100005],last[100005];
int main(){
    int n,k,l,r;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)
        scanf("%d",&need[i]);
    l = 1,r = n+1;
    while(l<r){
        int mid = (l+r)/2,countt = 0,subj = 0;
        for(int i=mid;i>=1;i--){
            if(last[a[i]] == 0 && a[i]){
                last[a[i]] = i;
            }
        }
        for(int i=1;i<=mid;i++){
            if(last[a[i]] == i){
                if(countt>=need[a[i]]){
                    countt-=need[a[i]];
                    subj++;
                }
            }else{
                countt++;
            }
        }
        memset(last,0,sizeof last);
        if(subj == k)   r = mid;
        else            l = mid+1;
    }
    printf("%d\n",(l == n+1)? -1 : l);
    return 0;
}
