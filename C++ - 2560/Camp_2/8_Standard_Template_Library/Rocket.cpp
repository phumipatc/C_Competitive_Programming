/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct{
    int s,f;
}I;
I a[70000];
bool com(I i,I j){
    return i.s<j.s;
}
bool com2(I i,I j){
    return i.f<j.f;
}
int sortbys[62000],sortbyf[62000];
int main(){
    int i,n,x,q,countt=0,tmp,k;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].s,&a[i].f);
    }
    for(i=0;i<=50000;i++)   sortbyf[i]=sortbys[i]=0;
    sort(a,a+n,com);
    for(i=0;i<n;i++)   sortbys[i]=a[i].s;
    sort(a,a+n,com2);
    for(i=0;i<n;i++) sortbyf[i]=a[i].f;
    while(q--){
        scanf("%d",&k);
        x=(int)(upper_bound(sortbyf,sortbyf+n,k)-sortbyf);
        tmp=(int)(lower_bound(sortbys,sortbys+n,k)-sortbys);
        countt=(countt+tmp-x)%2007;
//        printf("u: %d\nl: %d\ncountt: %d\n",x,tmp,countt);
    }
    printf("%d\n",countt);
    return 0;
}
