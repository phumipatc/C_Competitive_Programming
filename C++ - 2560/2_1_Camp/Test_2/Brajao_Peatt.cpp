/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,num;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x<o.x;
        return y<o.y;
    }
};
A a[100100];
int main()
{
    int n,m,l,x,y;
    cin >> n >> m >> l;
    for(int i=1;i<=m;i++){
        int x;
        cin >> x;
        a[i].x=x,a[i].y=0,a[i].num=i;
    }
    for(int i=m+1;i<=m+l;i++){
        int y;
        cin >> y;
        a[i].y=y,a[i].x=0,a[i].num=i;
    }
    sort(a+1,a+m+l+1);
    while(n--){
        double ans;
        int pos,minn=1e9;
        cin >> x >> y;
        for(int i=1;i<=m+l;i++){
            ans=sqrt(((a[i].x-x)*(a[i].x-x))+((a[i].y-y)*(a[i].y-y)));
            if(minn==ans){
                pos=min(a[i].num,pos);
            }else if(minn>ans){
                minn=ans;
                pos=a[i].num;
            }
            cout << ans << " " << minn << " " << pos << endl;
        }
        cout << pos << endl;
    }
    return 0;
}
