/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,id;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v<o.v;
        else        return id<o.id;
    }
};
priority_queue< A> heap;
int a[1000100],mark[1000100];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,l,c;
    scanf("%d %d %d",&n,&l,&c);
    for(int i=1;i<=n;i++)
        heap.push({0,i});
    int q = l+c;
    char opr;
    while(q--){
        scanf(" %c",&opr);
        if(opr == 'L'){
            scanf("%d %d",&l,&c);
            a[c]++;
            heap.push({a[c],c});
        }else if(opr == 'C'){
            scanf("%d %d",&l,&c);
            a[c]+=3;
            heap.push({a[c],c});
        }else if(opr == 'R'){
            while(!heap.empty() && mark[heap.top().id])
                heap.pop();
            printf("%d\n",heap.top().id);
        }else if(opr == 'D'){
            while(!heap.empty() && mark[heap.top().id])
                heap.pop();
            mark[heap.top().id] = 1;
            heap.pop();
        }
    }
    return 0;
}
