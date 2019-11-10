/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[10],a[10],ans[10],k,sum;
void permute(int now,int countt){
//    printf("%d %d %d\n",now,countt,sum);
    if(countt==k){
        ans[countt]=a[now];
        for(int i=1;i<k;i++){
            printf("%d",ans[i]);
            if(i%2==1)  printf("+");
            else        printf("-");
        }
        printf("%d=",ans[k]);
        if(k%2==0)      printf("%d\n",ans[k]+sum);
        else if(k!=1)   printf("%d\n",sum-ans[k]);
        else            printf("%d\n",ans[k]);
        return ;
    }
    mark[now]=1;
    if(countt!=1){
        if(countt%2==0) sum+=a[now];
        else            sum-=a[now];
    }
    ans[countt]=a[now];
    for(int i=1;i<=k;i++)
        if(mark[i]==0)
            permute(i,countt+1);
    if(countt!=1){
        if(countt%2==0) sum-=a[now];
        else            sum+=a[now];
    }
    mark[now]=0;
}
int main(){
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++){
        sum=a[i];
        permute(i,1);
    }
    return 0;
}
