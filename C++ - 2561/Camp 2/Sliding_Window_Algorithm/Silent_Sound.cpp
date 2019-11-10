/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
};
A now;
deque<A > maxx,minn;
int main(){
    int n,m,c,temp,ch = 0;
    scanf("%d %d %d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        while(!maxx.empty() && maxx.back().v<temp)  maxx.pop_back();
        while(!minn.empty() && minn.back().v>temp)  minn.pop_back();

        while(!maxx.empty() && maxx.front().idx<=i-m)   maxx.pop_front();
        while(!minn.empty() && minn.front().idx<=i-m)   minn.pop_front();
        maxx.push_back({i,temp});
        minn.push_back({i,temp});
        if(i>=m){
            if(maxx.front().v-minn.front().v<=c){
                printf("%d\n",i-m+1);
                ch = 1;
            }
        }
    }
    if(!ch) printf("NONE\n");
	return 0;
}
