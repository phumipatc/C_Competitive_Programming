/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int> man_short,man_tall,woman_short,woman_tall;
int main()
{
    int i,n,num,minn;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        if(num<0)
            man_short.push(num);
        else
            man_tall.push(-num);
    }
    for(i=0;i<n;i++){
        cin >> num;
        if(num<0)
            woman_short.push(num);
        else
            woman_tall.push(-num);
    }
    int ans=0;
    while(!man_short.empty() && !woman_tall.empty()){
        if(-man_short.top()<=-woman_tall.top())   man_short.pop();
        else                                      man_short.pop(),woman_tall.pop(),ans++;
    }
    while(!man_tall.empty() && !woman_short.empty()){
        if(-woman_short.top()<=-man_tall.top())   woman_short.pop();
        else                                      woman_short.pop(),man_tall.pop(),ans++;
    }
    cout << ans << endl;
    return 0;
}
