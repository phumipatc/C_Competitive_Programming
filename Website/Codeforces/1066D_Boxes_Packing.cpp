/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l = 1,r = n+1,mid,sum,countt;
    while(l<r){
        mid = (l+r)/2,sum = 0,countt = 0;
        for(int i=mid;i<=n;i++){
            if(sum+a[i]<=k) sum+=a[i];
            else{
                if(a[i]>k){
                    countt = 1e9;
                    break;
                }else{
                    sum = a[i];
                    countt++;
                }
            }
        }
        if(sum) countt++;
        if(countt>m)    l = mid+1;
        else            r = mid;
    }
    printf("%d\n",n-l+1);
	return 0;
}