/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int price,index;
    bool operator < (const A&o) const{
        if(price > o.price)
            return true;
        else
            return false;
    }
};
priority_queue< A> heap;
int a[500100];
int main(){
    int n,k,i;
    A temp;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    temp.price=a[0];
    temp.index=0;
    heap.push(temp);
    for(i=1;i<n;i++){
        while(!heap.empty()){
            if(i-k>heap.top().index){
                //printf("--\n");
                heap.pop();
                continue;
            }
            //printf("%d\n",heap.top().price);
            a[i]+=heap.top().price;
            temp.price=a[i];
            temp.index=i;
            heap.push(temp);
            break;
        }
    }
    printf("%d",a[n-1]);
    return 0;
}
