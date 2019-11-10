/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    if(m == 0 || m == 1){
        printf("1\n");
        return 0;
    }
    if(m<=n/2)  printf("%d\n",m);
    else        printf("%d\n",n-m);
	return 0;
}
