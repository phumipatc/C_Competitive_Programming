/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[1100];
struct A{
    long long fir,sec,weight;
    bool operator < (const A&o) const{
        return weight < o.weight;
    }
};
long long findroot(int i){
    if(p[i]==i)
        return i;
    return p[i]=findroot(p[i]);
}
A a[2000000];
int main(){
    long long n,i,j,num=0,sum=0,ra,rb;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            num++;
            scanf("%lld",&a[num].weight);
            a[num].fir=i;
            a[num].sec=j;
        }
    }
    for(i=1;i<=n;i++){
        num++;
        scanf("%lld",&a[num].weight);
        a[num].fir=i;
        a[num].sec=n+1;
    }
    sort(a+1,a+num+1);
    //for(i=1;i<=num;i++){
        //printf("%d ",a[i].weight);
    //}
    for(i=1;i<=n;i++){
        p[i]=i;
    }
    for(i=1;i<=num;i++){
        ra=findroot(a[i].fir);
        rb=findroot(a[i].sec);
        if(ra!=rb){
            p[rb]=ra;
            sum+=a[i].weight;
        }
    }
    printf("%lld\n",sum);
	return 0;
}
