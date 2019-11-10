/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b,num;
    bool operator<(const A&o)const{
        if(a!=o.a)  return a<o.a;
    }
};
int ans[1000100],mark[500100];
A a[1000100];
priority_queue< int > heap;
int main()
{
    int n,k,q,i;
    scanf("%d %d %d",&n,&k,&q);
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i].a,&a[i].b);
        a[i].num=i+1;
    }
    sort(a,a+n);
    heap.push(a[0].b*-1);
    mark[a[0].num]=1;
    for(i=1;i<n;i++){
        while(!heap.empty()&&(a[i].a*-1)<heap.top()){
            heap.pop();
        }
        if(heap.size()<k)
            heap.push(a[i].b*-1),mark[a[i].num]=1;
    }

    while(q--){
        scanf("%d",&n);
        if(mark[n]) printf("Y ");
        else        printf("N ");
    }
    return 0;
}
/*
6 1 4
3 7 2 4 1 3 7 8 8 10 9 15
3 5 4 1
*/

