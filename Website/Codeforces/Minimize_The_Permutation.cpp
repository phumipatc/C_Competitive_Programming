/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110],mark[110];
int main(){
    int q,n,minn,idx;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(mark,0,sizeof mark);
        for(int i=1;i<n;i++){
            minn = a[i],idx = i;
            for(int j=i+1;j<=n;j++){
                if(mark[j-1])   break;
                if(minn>a[j]){
                    minn = a[j];
                    idx = j;
                }
            }
            for(int j=idx-1;j>=i;j--){
                swap(a[j],a[j+1]);
                mark[j] = 1;
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}