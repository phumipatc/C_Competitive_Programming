/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int h,l,now,r;
    bool operator < (const A& o) const{
        return h<o.h;
    }
};
priority_queue<A> bottle;
A temp;
int mark[100100];
int main()
{
    int hh;
    int n,m,i,coun;
    scanf(" %d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf(" %d",&temp.h);
        temp.now=i;
        temp.l=i-1;
        temp.r=i+1;
        bottle.push(temp);
    }
    mark[0]=mark[n+1]=1;
    for(i=1;i<=m;i++){
        scanf(" %d",&hh);
        coun=0;
        while(!bottle.empty() && hh<bottle.top().h){
            temp=bottle.top();
            if(mark[bottle.top().now]!=0 && mark[bottle.top().now]<i){
                bottle.pop();
                continue;
            }
            if(mark[temp.now]==0)   mark[temp.now]=i,coun++;
            if(mark[temp.l]==0)     mark[temp.l]=i,coun++;
            if(mark[temp.r]==0)     mark[temp.r]=i,coun++;
            bottle.pop();
        }
        printf("%d\n",coun);
    }
    return 0;
}
/*
7 4
3 1 4 6 7 3 5
5 4 6 2

*/
