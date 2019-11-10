/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,id;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x>o.x;
        else        return y<o.y;
    }
};
A a[1000010];
struct B{
    int x,y;
    bool operator < (const B&o) const{
        if(x!=o.x)  return x>o.x;
        else        return y>o.y;
    }
};
B now;
priority_queue<B > heap;
int mark[1000010];
int main(){
    int n,x,y;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        a[i] = {x,y,i};
    }
    sort(a+1,a+n+1);
    int maxx = 0;
    for(int i=1;i<=n;i++){
        if(maxx>a[i].y){
            mark[a[i].id] = 1;
        }else{
            maxx = a[i].y;
            heap.push({a[i].x,a[i].y});
        }
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        printf("%d %d\n",now.x,now.y);
    }
	return 0;
}
