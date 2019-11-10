/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],need[200001];
int main(){
    int q,ans,st,v,n,c,now;
    scanf("%d",&q);
    while(q--){
        ans = st = v = 0;
        scanf("%d %d",&n,&c);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),a[i+n] = a[i];
        for(int i=0;i<n;i++)
            scanf("%d",&b[i]),b[i+n] = b[i];
        for(int i=0;i<2*n;i++){
            v = min(v+a[i],c)-b[i];
            if(v<0){
                st = i+1;
                v = 0;
            }
        }
        if(st>n){
            printf("0\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
