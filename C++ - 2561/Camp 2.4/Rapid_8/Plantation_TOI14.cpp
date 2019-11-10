/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double x,y;
	bool operator < (const A&o) const{
		return x<o.x;
	}
};
A a[100010];
int stripe[100010];
bool cmpy(int i,int j){
    return a[i].y<a[j].y;
}
double dis(int i,int j){
    return sqrt(((a[i].x-a[j].x)*(a[i].x-a[j].x))+((a[i].y-a[j].y)*(a[i].y-a[j].y)));
}
double min_dis(int l,int r){
    if(l == r)      return 1e9;
    if(l+1 == r)    return dis(l,r);
    double minn = 1e9;
    int mid = (l+r)/2,k = 1;
    minn = min(min_dis(l,mid),min_dis(mid+1,r));
    for(int i=l;i<=r;i++){
        if(max(minn,fabs(a[mid].x - a[i].x))!=minn)	continue;
        stripe[k++] = i;
    }
    sort(stripe+1,stripe+k,cmpy);
    double temp = minn;
    for(int i=1;i<k;i++)
        for(int j=i+1;j<k && max(temp,a[stripe[j]].y-a[stripe[i]].y) == temp;j++)
            minn = min(minn,dis(stripe[i],stripe[j]));
    return minn;
}
int main(){
    int q,n,r;
    double ans,d;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %lf",&n,&r,&d);
        for(int i=1;i<=n;i++)
            scanf("%lf %lf",&a[i].x,&a[i].y);
        sort(a+1,a+n+1);
        ans = min_dis(1,n);
        if(min(ans-(2*r),d) == d)   printf("Y\n");
        else                        printf("N\n");
    }
	return 0;
}
