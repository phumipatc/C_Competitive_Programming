/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
deque<int > maxx,minn;
queue<int > ans;
int main(){
    int n,m,c;
    scanf("%d %d %d",&n,&m,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        while(!maxx.empty() && maxx.front()<i-m+1)      maxx.pop_front();
        while(!minn.empty() && minn.front()<i-m+1)      minn.pop_front();
        while(!maxx.empty() && a[maxx.back()]<=a[i])    maxx.pop_back();
        while(!minn.empty() && a[minn.back()]>=a[i])    minn.pop_back();
        maxx.push_back(i);
        minn.push_back(i);
        if(i>=m){
            if(a[maxx.front()]-a[minn.front()]<=c){
                ans.push(i-m+1);
            }
        }
    }
    if(ans.size() == 0) printf("NONE\n");
    else{
        while(!ans.empty()){
            printf("%d\n",ans.front());
            ans.pop();
        }
    }
	return 0;
}
