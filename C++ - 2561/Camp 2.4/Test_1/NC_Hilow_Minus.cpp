/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
deque<int > deq;
int a[1000010],dif[1000010];
int main(){
    int n,m,minn = 1e9;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        dif[i] = a[i+1]-a[i];
    for(int i=1;i<n;i++){
        while(!deq.empty() && i-deq.front()+1>n-m)      deq.pop_front();
        while(!deq.empty() && dif[deq.back()]>=dif[i])  deq.pop_back();
        deq.push_back(i);
        if(i-(n-m)>=0)
            minn = min(minn,a[i]-a[i-(n-m)+1]+dif[deq.front()]);
    }
    printf("%d\n",minn);
	return 0;
}
