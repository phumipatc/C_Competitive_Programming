/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int w,s;
};
A a[100001];
int countt[100001];
int main(){
    int q,n,k,i,ch,maxx,sum;
    scanf("%d",&q);
    while(q--){
        ch=0,maxx=-1,sum=0;
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a[i].w,&a[i].s);
            countt[a[i].s]++;
            maxx=max(maxx,a[i].w);
            sum+=a[i].w;
            if(countt[a[i].s]>k)    ch=1;
        }
        if(ch){
            printf("-1\n");
            continue;
        }
        memset(countt,0,sizeof countt);
        int l=maxx,r=sum+1,now=1,val,box;
        while(l<r){
            int mid=(l+r)/2;
            now++;
            for(i=1,val=0,box=1;i<=n;i++){
                if(val+a[i].w>mid || countt[a[i].s]==now){
                    box++;
                    val=a[i].w;
                    now++;
                }else
                    val+=a[i].w;
                countt[a[i].s]=now;
            }
            if(box<=k)  r=mid;
            else        l=mid+1;
        }
        if(r>sum)
            printf("-1");
        else
            printf("%d\n",r);
        memset(countt,0,sizeof countt);
    }
    return 0;
}
