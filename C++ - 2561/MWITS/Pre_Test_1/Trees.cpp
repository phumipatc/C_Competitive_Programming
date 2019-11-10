/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    bool operator < (const A&o) const{
        if(u!=o.u)  return u<o.u;
        else        return v<o.v;
    }
};
A a[200010],b[200010];
int main(){
    int q = 5,n,u,v;
    while(q--){
        cin >> n;
        for(int i=1;i<n;i++){
            cin >> a[i].u >> a[i].v;
            if(a[i].u>a[i].v)   swap(a[i].u,a[i].v);
        }
        for(int i=1;i<n;i++){
            cin >> b[i].u >> b[i].v;
            if(b[i].u>b[i].v)   swap(b[i].u,b[i].v);
        }
        sort(a+1,a+n);
        sort(b+1,b+n);
        int ch = 1;
        for(int i=1;i<n;i++){
            if((a[i].u != b[i].u) || (a[i].v != b[i].v)){
                ch = 0;
                break;
            }
        }
        if(ch)  printf("Y");
        else    printf("N");
    }
	return 0;
}
