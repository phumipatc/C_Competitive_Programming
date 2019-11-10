/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
deque< int> maxx,minn;
int main()
{
    int n,m,c,i,ch=0;
    scanf("%d %d %d",&n,&m,&c);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        while(!maxx.empty() && a[maxx.back()]<a[i]) maxx.pop_back();
        while(!maxx.empty() && maxx.front()<=i-m)   maxx.pop_front();
        while(!minn.empty() && a[minn.back()]>=a[i]) minn.pop_back();
        while(!minn.empty() && minn.front()<=i-m)   minn.pop_front();
        maxx.push_back(i);
        minn.push_back(i);
        if(a[maxx.front()]-a[minn.front()]<=c && i>=m){
            printf("%d\n",i-m+1);
            ch=1;
        }
    }
    if(!ch){
        printf("NONE\n");
    }
    return 0;
}
