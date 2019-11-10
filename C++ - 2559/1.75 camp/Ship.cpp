/*
TASK: Ship
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int x[600],y[600];
int main(){
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    for(i=0;i<n;i++)
        ans+= abs(x[i]-(i+1));
    for(i=0;i<n;i++)
        ans+= abs(y[i]-(i+1));
    printf("%d\n",ans);
	return 0;
}
