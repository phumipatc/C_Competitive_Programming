/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[6],b[6];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,num;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            a[num]++;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            b[num]++;
        }
        int countt=0,countt2=0;
        for(int i=1;i<=5;i++){
            if((a[i]+b[i])%2){
                printf("-1\n");
                goto nextt;
            }
            if(a[i]>b[i])   countt2+=(a[i]-b[i])/2;
            if(b[i]>a[i])   countt+=(b[i]-a[i])/2;
        }
        if(countt==countt2)
            printf("%d\n",countt);
        else
            printf("-1\n");
        nextt:;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }
    return 0;
}
