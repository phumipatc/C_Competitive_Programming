/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,rank;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A a[100010];
int LIS[100010];
int main(){
    int n,k,maxx = 0,idx;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].rank,&a[i].pos);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        idx = upper_bound(LIS,LIS+maxx,a[i].rank)-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = a[i].rank;
    }
    printf("%d\n",maxx);
	return 0;
}