/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[300001];
int mark[300001];
int find_root(int n){
    if(p[n] == n)	return n;
    else			return p[n] = find_root(p[n]);
}
int main(){
    int q,l;
    scanf("%d %d",&q,&l);
    for(int i=1;i<=l;i++)	p[i] = i;
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        int ra = find_root(a);
        int rb = find_root(b);
        if(!mark[a]){
            mark[a] = 1,p[ra] = rb;
            printf("Yes\n");
            continue;
        }
        if(!mark[b]){
            mark[b] = 1,p[rb] = ra;
            printf("Yes\n");
            continue;
        }
        if(!mark[ra]){
            mark[ra] = 1,p[ra] = rb;
            printf("Yes\n");
            continue;
        }
        if(!mark[rb]){
            mark[rb] = 1,p[rb] = ra;
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
    return 0;
}
