/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    long long n = 1e6,r = 500,x,y;
    double ans = 0;
    for(long long i=1;i<=n;i++){
        x = rand()%1001;
        y = rand()%1001;
        x-=500,y-=500;
        // printf("%d %d\n",x,y);
        if((x*x)+(y*y)<=(r*r))  ans++;
    }
    printf("%f\n",4*(float )ans/n);
	return 0;
}
