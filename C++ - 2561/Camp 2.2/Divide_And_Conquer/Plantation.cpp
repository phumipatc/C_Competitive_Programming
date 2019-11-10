/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
};
A a[100010];
bool cmpx(A a,A b){
    return a.x<b.x;
}
bool cmpy(A a,A b){
    return a.y<b.y;
}
double dis(A a,A b){
    return sqrt((double)((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}
double divide(A b[],int n){
    double minn = 2e9,dl,dr,d;
    if(n<=3){
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                minn = min(minn,dis(b[i],b[j]));
        return minn;
    }
    int mid = n/2;
    A temp = b[mid];
    dl = divide(b,mid);
    dr = divide(b+mid,n-mid);
    d = min(dl,dr);
    A strip[n+3],midp = b[mid];
    int countt = 0;
    for(int i=0;i<n;i++)
        if(abs(b[i].x-midp.x)<=d)
            strip[countt++] = b[i];
    sort(strip,strip+countt,cmpy);
    double tempp = d;
    for(int i=0;i<countt;i++)
        for(int j=i+1;j<countt && abs(strip[i].y-strip[j].y)<=tempp;j++)
            d = min(d,dis(strip[i],strip[j]));
    return d;
}
int main(){
    int q,n,r,d;
    double dist;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&n,&r,&d);
        for(int i=0;i<n;i++)
            scanf("%lld %lld",&a[i].x,&a[i].y);
        sort(a,a+n,cmpx);
        dist = divide(a,n);
        if(dist>= d+(2*r))  printf("Y\n");
        else                printf("N\n");
    }
	return 0;
}
