/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int now,change;
};
A a[1100];
int main(){
    int n,m,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].now,&a[i].change);
    while(m--){
        scanf("%d",&num);
        for(int i=1;i<=n;i++){
            if(a[i].now<=num)
                swap(a[i].now,a[i].change);
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",a[i].now);
	return 0;
}
