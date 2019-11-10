/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int sti,stj,eni,enj;
};
A a[1010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d %d",&a[i].sti,&a[i].stj,&a[i].eni,&a[i].enj);
    while(m--){
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    }
	return 0;
}
