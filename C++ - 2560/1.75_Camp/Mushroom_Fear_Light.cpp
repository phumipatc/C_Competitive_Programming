/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> heap;
int main()
{
    long long L,H,mushroom;
    int n,i,x,y,Ai;
    scanf("%d %lld %lld",&n,&L,&H);
    while(n--){
        scanf(" %d",&Ai);
        for(i=0;i<Ai;i++){
            scanf(" %lld",&mushroom);
            heap.push(mushroom);
        }
        scanf(" %d %d",&x,&y);
        while(!heap.empty() && (heap.top()-L)*y>=x*H)    heap.pop();
        printf("%d\n",(int)heap.size());
    }
    return 0;
}
