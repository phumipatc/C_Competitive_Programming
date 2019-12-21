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
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
        {
            cout << "YES\n";
            continue;
        }
        if (a && b && c)
        {
            cout << "YES\n";
            continue;
        }
        if (!a && !b)
        {
            if (c == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        if (!a && !c)
        {
            if (b == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        if (!b && !c)
        {
            if (a == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        if (!a)
        {
            if (b > 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if (!b)
        {
            if (c > 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
        if (!c)
        {
            if (a > 1)
                cout << "NO\n";
            else
                cout << "YES\n";
            continue;
        }
    }
}