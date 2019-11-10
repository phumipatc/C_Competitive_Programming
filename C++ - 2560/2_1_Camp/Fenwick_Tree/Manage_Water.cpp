/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[2100][2100];
int query(int x,int y){
    int sum=0;
    for(int i=x;i>0;i-=(i & -i)){
        for(int j=y;j>0;j-=(j & -j)){
            sum+=tree[i][j];
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n >> n;
    while(1){
        int q;
        cin >> q;
        if(q==3)    return 0;
        if(q==1){
            int x,y,c;
            cin >> x >> y >> c;
            x++,y++;
            for(int i=x;i<=n;i+=(i & -i)){
                for(int j=y;j<=n;j+=(j & -j)){
                    tree[i][j]+=c;
                }
            }
        }
        if(q==2){
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x2++,y2++;
            cout << query(x2,y2)-query(x1,y2)-query(x2,y1)+query(x1,y1) << endl;
        }
    }
    return 0;
}
/*
0 4
1 1 2 3
2 0 0 2 2
1 1 1 2
1 1 2 -1
2 1 1 2 3
3
*/
