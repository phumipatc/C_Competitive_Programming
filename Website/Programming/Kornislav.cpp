/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    for(int i=1;i<=4;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+5);
    printf("%d\n",min(a[1],a[2])*min(a[3],a[4]));
	return 0;
}
