/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator < (const A&o) const{
        if(x<o.x)       return ...;
        else if(x>o.x)  return ...;
        else if(y<o.y)  return ...;
        else            return ...;
    }
};
A a[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",a[i].x,a[i].y);
	return 0;
}   