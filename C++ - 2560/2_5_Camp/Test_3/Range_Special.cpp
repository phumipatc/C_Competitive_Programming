/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,v;
};
deque< A> maxx,minn;
int a[1000005];
int main(){
    int n,p,q;
    scanf("%d %d %d",&n,&p,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(!maxx.empty() && maxx.back().v<a[i])  maxx.pop_back();
        while(!minn.empty() && minn.back().v>a[i])  minn.pop_back();
    }
    return 0;
}
