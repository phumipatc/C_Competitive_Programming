/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100100];
int main()
{
    int n,k,buff,maxv=-1,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    sort(a,a+n);
    int l=1,h=1000000000,m,t,pos;
    while(h>=l){
        m=(h+l)/2,t=0,pos=0;
        for(i=0;i<k-1;i++){
			if(a[pos]+m>a[n-1]){
                t=1;break;
            }else{
				buff=a[pos]+m;
				pos=lower_bound(&a[0],&a[n-1],buff)-a;
			}
		}
        if(m>maxv&&t==0)maxv=m;
        if(t==1)h=m-1;
        else l=m+1;
	}
    printf("%d\n",maxv);
	return 0;
}
