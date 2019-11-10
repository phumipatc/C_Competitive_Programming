/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
double x[5010],y[5010];
int main(){
    int n;
    double m,maxx,maxy;
    scanf("%lf %d",&m,&n);
    for(int i=0;i<n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);

    maxx = max(x[0],m-x[n-1]);
    maxy = max(y[0],m-y[n-1]);
    for(int i=0;i<n-1;i++){
        maxx = max(maxx,(x[i+1]-x[i])/2);
        maxy = max(maxy,(y[i+1]-y[i])/2);
    }
    printf("%.3lf\n",min(maxx,maxy));
	return 0;
}
