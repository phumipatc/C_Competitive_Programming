/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],l[100010],l2[100010],r[100010],r2[100010];
int main(){
    int q,n,maxx,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        l[1] = l2[1] = 1;
        for(int i=2;i<=n;i++){
            l[i] = l2[i] = 1;
            if(a[i]-a[i-1]>=1 && a[i]-a[i-1]<=2)
                l[i]+=l[i-1];
            if(a[i-1]-a[i]>=1 && a[i-1]-a[i]<=2)
                l2[i]+=l2[i-1];
        }
        r[n] = r2[n] = 1;
        for(int i=n-1;i>=1;i--){
            r[i] = r2[i] = 1;
            if(a[i]-a[i+1]>=1 && a[i]-a[i+1]<=2)
                r[i]+=r[i+1];
            if(a[i+1]-a[i]>=1 && a[i+1]-a[i]<=2)
                r2[i]+=r2[i+1];
        }
        maxx = max(r[2]+1,r2[2]+1);
        now = 1;
        for(int i=2;i<n;i++){
            if(a[i+1]-a[i-1]>=2 && a[i+1]-a[i-1]<=4){
                if(maxx<l[i-1]+r2[i+1]+1){
                    maxx = l[i-1]+r2[i+1]+1;
                    now = i;
                }
            }
            if(a[i-1]-a[i+1]>=2 && a[i-1]-a[i+1]<=4){
                if(maxx<l2[i-1]+r[i+1]+1){
                    maxx = l2[i-1]+r[i+1]+1;
                    now = i;
                }
            }
            if(maxx<l[i-1]+1 || maxx<l2[i-1]+1 || maxx<r[i+1]+1 || maxx<r2[i+1]+1){
                maxx = max(l[i-1]+1,max(l2[i-1]+1,max(r[i+1]+1,r2[i+1]+1)));
                now = i;
            }
        }
        if(maxx<l[n-1]+1){
            maxx = l[n-1]+1;
            now = n;
        }
        if(maxx<l2[n-1]+1){
            maxx = l2[n-1]+1;
            now = n;
        }
        printf("%d %d\n",maxx,now-1);
    }
	return 0;
}
/*
4
12 20 10 11 11 15 10 17 16 10 12 20 20
7
0 0 0 0 0 0 0
5
1 2 3 2 1
10
0 5 6 7 8 0 20 21 22 23
*/
