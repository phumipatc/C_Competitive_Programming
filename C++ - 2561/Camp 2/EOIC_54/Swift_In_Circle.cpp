/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n;
    double r;
    scanf("%d",&q);
    while(q--){
        scanf("%d %lf",&n,&r);
        printf("%.1lf\n",n*r*r*sin((double)acos(-1)/n)*cos((double)acos(-1)/n));
    }
	return 0;
}
