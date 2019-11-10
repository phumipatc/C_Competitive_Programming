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
A a[200010];
int main(){
    int n,st,en;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&st,&en);
        a[i] = {st,1},a[i+n] = {en+1,-1};
    }
    sort(a+1,a+(2*n)+1);
    int maxx = 0,sum = 0;
    for(int i=1;i<=2*n;i++){
        sum+=a[i].v;
        maxx = max(maxx,sum);
    }
    printf("%d\n",maxx);
	return 0;
}
