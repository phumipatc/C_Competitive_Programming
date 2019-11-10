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
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]),a[i]*=10;
    sort(a+1,a+m+1);
    int l = 0,r = 1e9;
    while(l<r){
        int mid = (l+r)/2,sum = a[1]+mid,countt = 1;
        for(int i=2;i<=m;i++){
            if(sum+mid<a[i])
                countt++,sum = a[i]+mid;
        }
        if(countt<=n)   r = mid;
        else            l = mid+1;
    }
    printf("%d.%d\n",l/10,l%10);
	return 0;
}
