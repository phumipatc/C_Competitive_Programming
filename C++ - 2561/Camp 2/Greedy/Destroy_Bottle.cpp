/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int h,id;
    bool operator < (const A&o) const{
        return h<o.h;
    }
};
A now;
priority_queue<A > heap;
int mark[100010],a[100010];
int main(){
    int n,m,temp,countt;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        heap.push({a[i],i});
    }
    while(m--){
        scanf("%d",&temp);
        countt = 0;
        while(!heap.empty() && heap.top().h>temp){
            now = heap.top();
            heap.pop();
            if(mark[now.id])    continue;
            countt++;
            mark[now.id] = 1;
//            printf("%d\n",now.id);
            if(now.id-1>=1 && a[now.id-1]<=temp && !mark[now.id-1]){
                mark[now.id-1] = 1;
                countt++;
//                printf("%d\n",now.id-1);
            }
            if(now.id+1<=n && a[now.id+1]<=temp && !mark[now.id+1]){
                mark[now.id+1] = 1;
                countt++;
//                printf("%d\n",now.id+1);
            }
        }
        printf("%d\n",countt);
    }
	return 0;
}
