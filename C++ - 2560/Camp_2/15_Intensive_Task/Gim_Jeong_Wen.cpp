/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
double x[5050],y[5050],m,mx,my;
int main()
{
    int n,i;
    scanf("%lf %d",&m,&n);
    for(i=0; i<n; i++)
        scanf("%lf %lf",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);

    mx = max(x[0],m-x[n-1]);
    for(i=1; i<n-1; i++)
        if((x[i+1]-x[i])/2>mx)
            mx=(x[i+1]-x[i])/2;

    my = max(y[0],m-y[n-1]);
    for(i=1; i<n-1; i++)
       if((y[i+1]-y[i])/2>my)
            my=(y[i+1]-y[i])/2;

    printf("%.3lf\n",min(mx,my));
    return 0;
}
/*
1
2
1 1
0 0
---
0.500

10
5
9 5
7 5
5 5
3 5
1 5
---
1.000
*/
