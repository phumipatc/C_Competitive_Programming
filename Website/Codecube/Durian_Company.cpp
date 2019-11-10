/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,v;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos<o.pos;
        else            return v<o.v;
    }
};
A a[2000010];
int main(){
    int n,sum = 0,maxx = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].pos >> a[i+n].pos;
        a[i].v = 1,a[i+n].v = -1;
    }
    sort(a+1,a+(2*n)+1);
    for(int i=1;i<=(2*n);i++){
        sum+=a[i].v;
        maxx = max(maxx,sum);
        // printf("%d %d\n",a[i].pos,sum);
    }
    printf("%d\n",maxx);
	return 0;
}
