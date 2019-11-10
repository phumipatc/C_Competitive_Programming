/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,v;
};
int a[6000010];
deque<A > deq;
int main(){
    int n,w,sum = 0,temp,maxx = 0,ans;
    scanf("%d %d",&n,&w);
    deq.push_back({0,0});
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        sum+=temp;
        while(!deq.empty() && deq.front().pos<i-w)  deq.pop_front();
        while(!deq.empty() && deq.back().v>=sum)    deq.pop_back();
        deq.push_back({i,sum});
        if(sum-deq.front().v>maxx){
            maxx = sum-deq.front().v;
            ans = i-deq.front().pos;
        }else if(sum-deq.front().v == maxx){
            ans = min(ans,i-deq.front().pos);
        }
    }
    if(maxx == 0)   printf("0\n0\n");
    else            printf("%d\n%d\n",maxx,ans);
	return 0;
}
