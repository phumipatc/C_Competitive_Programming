/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],idx[100005],countt[100005];
void merge_sort(int l,int r){
    if(l == r)  return ;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i = l,j = mid+1,k = l;
    while(i<=mid && j<=r){
        if(a[i]>a[j]){
            b[k++] = a[j++];
            for(int l=i;l<=mid;l++)
                countt[a[l]]++;
        }else
            b[k++] = a[i++];
    }
    while(i<=mid)   b[k++] = a[i++];
    while(j<=r)     b[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = b[i];
}
int main(){
    int q,n,ch,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ch = ans = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            idx[a[i]] = i;
        }
        merge_sort(1,n);
        for(int i=1;i<=n;i++){
            if(countt[i]>2){
                printf("CHEAT\n");
                ch = 1;
                break;
            }
            ans+=countt[i];
        }
        if(!ch) printf("%d\n",ans);
        memset(countt,0,sizeof countt);
    }
    return 0;
}
