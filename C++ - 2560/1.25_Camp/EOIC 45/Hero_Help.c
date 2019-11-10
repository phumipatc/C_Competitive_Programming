/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010];
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i =0;i<n;i++)
        cin >> x[i] >> y[i];
    sort(x,x+n);
    sort(y,y+n);
    int ans = 0,index;
    for(int i=0;i<n;i++)
    {
        index = lower_bound(x,x+n,x[i] + k) - x;
        ans = max(ans,index - i);

        index = lower_bound(y,y+n,y[i] + k) - y;
        ans = max(ans,index - i);
    }
    cout << ans;
    return 0;
}
