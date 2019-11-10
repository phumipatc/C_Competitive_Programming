/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int val,idx;
};
A a[6000100];
deque< A> deq;
int main()
{
    int ans=-1,n,k,i,len;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i].val);
        a[i].val+=a[i-1].val;
        a[i].idx=i;
    }
    deq.push_back({0,0});
    for(i=1;i<=n;i++){
        while(!deq.empty()&&deq.back().val>=a[i].val)     deq.pop_back();
        while(!deq.empty()&&i-deq.front().idx>k)          deq.pop_front();
        deq.push_back(A{a[i].val,a[i].idx});
        if(deq.back().val-deq.front().val==ans)
        {
            len=min(len,deq.back().idx-deq.front().idx);
        }
        if(deq.back().val-deq.front().val>=ans)
        {
            ans=deq.back().val-deq.front().val;
            len=deq.back().idx-deq.front().idx;
        }
    }
    if(ans<0)   printf("0\n0\n");
    else
        printf("%d\n%d\n",ans,len);
    return 0;
}
/*
7 4
3
2
5
1
4
-7
10

7 3
3
2
5
1
4
-7
10
*/

