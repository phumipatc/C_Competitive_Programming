/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,val;
};
deque< A> deq;
int force[200010],use[200010];
int main(){
    int q,n,ans;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&force[i]),force[i+n] = force[i];
        for(int i=1;i<=n;i++)
            scanf("%d",&use[i]),use[i+n] = use[i];
        for(int i=1;i<=2*n;i++){
            deq.push_back({i,force[i]-use[i]});
            while(!deq.empty() && deq.back().val<0){
                int v = deq.back().val;
                deq.pop_back();
                if(!deq.empty())    deq.back().val+=v;
            }
            while(!deq.empty() && deq.front().pos == i-n){
                ans++;
                deq.pop_front();
            }
        }
        printf("%d\n",ans);
        while(!deq.empty()) deq.pop_back();
    }
    return 0;
}
