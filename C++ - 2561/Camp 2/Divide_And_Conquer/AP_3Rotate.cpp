/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],ans;
void merge_sort(int l,int r){
    if(l == r)  return ;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i = l,j = mid+1,k = l;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        }else{
            ans+=(mid-i+1);
            b[k++] = a[j++];
        }
    }
    while(i<=mid)   b[k++] = a[i++];
    while(j<=r)     b[k++] = a[j++];
    for(int k=l;k<=r;k++)
        a[k] = b[k];
}
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        merge_sort(1,n);
        if(ans%2 == 0)  printf("yes\n");
        else            printf("no\n");
    }
	return 0;
}
