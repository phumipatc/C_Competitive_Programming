/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator<(const A &o)const{
        if(x!=o.x)          return x<o.x;
        else                return y<o.y;
    }
};
A a[100100];
deque< A> minn;
deque< A> maxx;
int main(){
    int q,n,h,mi;
    scanf("%d",&q);
    while(q--){
        mi = 1e9;
        while(!maxx.empty())    maxx.pop_front();
        while(!minn.empty())    minn.pop_front();
        memset(a,0,sizeof a);
        scanf("%d %d",&n,&h);
        for(int i = 0 ; i < n ; i++)
            scanf("%d %d",&a[i].x,&a[i].y);
        sort(a,a+n);
        for(int i=0 ; i<n ; i++){
            while(!minn.empty() && minn.back().y>=a[i].y)    minn.pop_back();
            while(!maxx.empty() && maxx.back().y<=a[i].y)    maxx.pop_back();
            minn.push_back({a[i].x,a[i].y});
            maxx.push_back({a[i].x,a[i].y});
            while(maxx.front().y-minn.front().y>=h){
                mi = min(mi,abs(maxx.front().x-minn.front().x));
                if(maxx.front().x<minn.front().x)   maxx.pop_front();
                else                                minn.pop_front();
            }
        }
        if(mi == 1e9)   printf("-1");
        else            printf("%d\n",mi);
    }
}
