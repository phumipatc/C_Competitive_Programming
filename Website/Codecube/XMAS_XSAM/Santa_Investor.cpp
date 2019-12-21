/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n, last, now, dplast = 0, dpnow;
    cin >> n >> last;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        dpnow = max(now - last, 0ll) + dplast;
        dplast = dpnow;
        last = now;
    }
    cout << dpnow << '\n';
    return 0;
}