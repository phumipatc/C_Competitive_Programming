/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],w[100100],c[100100],mark[1000100];
int main(){
    long long q,n,k,maxx=-1,sum,l,r,mid,run=1,ch=0,summ,box,i;
    scanf("%lld",&q);
    while(q--){
        memset(mark,0,sizeof mark);
        ch=0,sum=0,maxx=-1;
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++){
            scanf("%lld %lld",&w[i],&c[i]);
            maxx=max(maxx,w[i]);
            sum+=w[i];
            mark[c[i]]++;
            if(mark[c[i]]>k)
                ch=1;
        }
        if(ch){
            printf("-1\n");
            continue;
        }
        memset(mark,0,sizeof mark);
        l=maxx,r=sum+1,run=0;
        while(l<r){
            mid=(l+r)/2;
            run++;
            for(i=0,summ=0,box=1;i<n;i++){
                if(summ+w[i]>mid || mark[c[i]]==run){
                    box++;
                    summ=w[i];
                    run++;
                    mark[c[i]]=run;
                }else{
                    summ+=w[i];
                    mark[c[i]]=run;
                }
            }
            //printf("%lld %lld %lld %lld\n",l,r,mid,box);
            if(box<=k)  r=mid;
            else        l=mid+1;
        }
        if(r>sum){
            printf("-1\n");
            continue;
        }
        printf("%lld\n",r);
    }
	return 0;
}
/*
2
5 3
10 1
10 2
40 1
30 3
30 4
5 2
10 1
10 2
40 1
30 3
30 1
*/
