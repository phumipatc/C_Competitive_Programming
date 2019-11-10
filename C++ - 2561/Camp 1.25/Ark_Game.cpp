/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,k,l = 1,r = 1e9,ans = -1e9,mid,ch,pos;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    while(l<r){
        mid = (l+r)/2,ch = 1,pos = 0;
        for(int i=1;i<k;i++){
            if(a[pos]+mid>a[n-1]){
                ch = 0;
                break;
            }else{
                pos = lower_bound(a,a+n,a[pos]+mid)-a;
            }
        }
        if(ch && mid>ans)   ans = mid;
        if(ch)  l = mid+1;
        else    r = mid;
    }
    printf("%d\n",ans);
	return 0;
}
