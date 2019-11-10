/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
priority_queue<int > heap;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!heap.empty()){
            if(-heap.top()<a[i])
                heap.pop();
        }
        heap.push(-a[i]);
    }
    printf("%d\n",heap.size());
    return 0;
}
