/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,c;
};
A a[100100];
int mark[100100];
int main(){
    int q,n,k,ch,l,r,now,mid,all,countt;
    scanf("%d",&q);
    while(q--){
        memset(mark,0,sizeof mark);
        ch = 0,l = -1e9,all = now = 0;
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].v,&a[i].c);
            l = max(l,a[i].v);
            all+=a[i].v;
            mark[a[i].c]++;
            if(mark[a[i].c]>k)  ch = 1;
        }
        if(ch){
            printf("-1\n");
            continue;
        }
        r = all+1;
        memset(mark,0,sizeof mark);
        while(l<r){
            mid = (l+r)/2,countt = 1;
            now++;
            for(int i=1,sum = 0;i<=n;i++){
                sum+=a[i].v;
                if(sum>mid || mark[a[i].c] == now){
                    sum = a[i].v;
                    now++;
                    countt++;
                }
                mark[a[i].c] = now;
            }
            if(countt<=k)   r = mid;
            else            l = mid+1;
        }
        if(l>all)   printf("-1\n");
        else        printf("%d\n",l);
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
