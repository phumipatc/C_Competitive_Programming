/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2000010],b[2000010],c[2000010];
int main(){
    int n,l,r,mid,idx,ch;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n/2;i++)
        b[i] = b[i*2];
    l = 0,r = n/2;
    while(l<r){
        mid = (l+r)/2,idx = 0,ch = 0;
        for(int i=1;i<=n;i++){
            if(a[i]<=b[mid])    continue;
            idx++;
            c[idx] = a[i];
        }
        for(int i=1;i<idx;i++){
            if(c[i]!=c[i+1]){
                ch = 1;
                break;
            }else{
                i++;
            }
        }
        if(ch)  l = mid+1;
        else    r = mid;
    }
    printf("%d\n",b[l]);
	return 0;
}
