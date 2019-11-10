/*
TASK: Farm tank
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
#define INF 2000000000
int a[100050]={0};
int main(){
    int mn=INF,i,n,m;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mn=MIN(mn,a[i]);
	}
    long long lo=0,hi=(long long)m*mn;
    while(lo<hi){
        long long mid=(lo+hi)/2,num=0;
        for(i=1;i<=n;i++) num+=mid/a[i];
        if(num<m) lo=mid+1;
        else hi=mid;
    }
    printf("%lld\n",lo);
    return 0;
}
