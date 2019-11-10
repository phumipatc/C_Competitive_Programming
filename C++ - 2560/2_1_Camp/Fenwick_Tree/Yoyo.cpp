/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
string a;
int tree[500500],n;
void up(int idx,int val){
    for(int i=idx;i<=n;i+=(i & -i))
        tree[i]+=val;
}
int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=(i & -i))
        sum+=tree[i];
    return sum;
}
int main()
{
    int m;
    cin >> n >> m;
    while(m--){
        cin >> a;
        if(a=="Yoyo"){
            int a,b,c;
            cin >> a >> b >> c;
            if(b>c) swap(b,c);
            up(b,a);
            up(c+1,-a);
        }else if(a=="Ask"){
            int d;
            cin >> d;
            cout << query(d) << endl;
        }
    }
    return 0;
}
/*
7 6
Yoyo 10 4 7
Yoyo 15 1 5
Ask 4
Yoyo 5 3 6
Ask 5
Ask 7
*/
