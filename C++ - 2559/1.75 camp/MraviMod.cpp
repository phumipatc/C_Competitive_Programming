/*
TASK: Mod
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int main(){
	int l,t,n,i,st;
	char b;
	scanf("%d %d %d",&l,&t,&n);
	for(i=0;i<n;i++){
        scanf("%d %c",&st,&b);
        if(b=='D'){
            st+=t;
            if( (st/l)%2 )  a[i]=l-(st%l);
            else            a[i]=st%l;
        }else if(b=='L'){
            st-=t;
            if(st>0)    a[i]=st%l;
            else{
                st*=-1;
                if( (st/l)%2 )  a[i]=l-(st%l);
                else            a[i]=st%l;
            }
        }
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
        printf("%d ",a[i]);
	return 0;
}
