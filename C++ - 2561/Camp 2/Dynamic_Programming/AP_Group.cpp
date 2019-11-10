/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(st!=o.st)    return st>o.st;
        else            return en<o.en;
    }
};
A a[100010];
int LIS[100010];
int main(){
    int q,n,maxx,idx;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].st,&a[i].en);
        sort(a+1,a+n+1);
        maxx = 0;
        for(int i=1;i<=n;i++){
            idx = upper_bound(LIS,LIS+maxx,a[i].en)-LIS;
//            if(idx>0 && LIS[idx-1] == a[i].en)  continue;
            if(idx == maxx) maxx++;
            LIS[idx] = a[i].en;
        }
        printf("%d\n",maxx);
    }
	return 0;
}
