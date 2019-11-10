/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    double x,y;
};
A a[100010];
bool cmpx(A i,A j){
    return i.x<j.x;
}
bool cmpy(int i,int j){
    return a[i].y<a[j].y;
}
double dis(int i,int j){
    return sqrt(((a[i].x-a[j].x)*(a[i].x-a[j].x))+((a[i].y-a[j].y)*(a[i].y-a[j].y)));
}
int temp[100010];
double divide(int l,int r){
    if(l == r)      return 1e9;
    if(l+1 == r)    return dis(l,r);
    double minn = 1e9;
    int mid = (l+r)>>1,k = 0;
    minn = min(divide(l,mid),divide(mid+1,r));
    for(int i=l;i<=r;i++){
        if(fabs(a[mid].x - a[i].x) <= minn)
            temp[k++] = i;
    }
    sort(temp,temp+k,cmpy);
    double t = minn;
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k && max(t,a[temp[j]].y-a[temp[i]].y) == t;j++){
            minn = min(minn,dis(temp[i],temp[j]));
        }
    }
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
        sort(a+1,a+n+1,cmpx);
        ans = divide(1,n);
        if(min(ans-(2*r),d) == d)   printf("Y\n");
        else                        printf("N\n");
    }
	return 0;
}
