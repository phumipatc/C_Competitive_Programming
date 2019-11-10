/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int find_root(int num){
    if(num == p[num])   return num;
    else                return p[num] = find_root(p[num]);
}
int main(){
    int n,m,a,b,ra,rb,q;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   p[i] = i;
    while(m--){
        scanf("%d %d",&a,&b);
        ra = find_root(a);
        rb = find_root(b);
        p[ra] = rb;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        ra = find_root(a);
        rb = find_root(b);
        if(ra == rb){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
	return 0;
}
