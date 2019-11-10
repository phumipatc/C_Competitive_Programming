/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
deque<int > deq;
int a[6000010];
int main(){
    int n,m,maxx = 0,len;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    deq.push_back(0);
    for(int i=1;i<=n;i++){
        while(!deq.empty() && deq.front()<i-m)      deq.pop_front();
        while(!deq.empty() && a[deq.back()]>=a[i])  deq.pop_back();
        deq.push_back(i);
        // printf("%d : %d %d\n",i,deq.front(),a[deq.front()]);
        if(maxx<a[i]-a[deq.front()]){
            maxx = a[i]-a[deq.front()];
            len = i-deq.front();
        }else if(maxx == a[i]-a[deq.front()]){
            len = min(len,i-deq.front());
        }
    }
    if(maxx == 0)   printf("0\n0\n");
    else            printf("%d\n%d\n",maxx,len);
	return 0;
}
