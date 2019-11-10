/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,v;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v>o.v;
        else        return id>o.id;
    }
};
A now;
priority_queue< A> heap;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++)
        heap.push({i,0});
    int num;
    while(n--){
        scanf("%d",&num);
        now = heap.top();
        heap.pop();
        printf("%d\n",now.id);
        now.v+=num;
        heap.push(now);
    }
	return 0;
}
