/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],num[100100];
int find_root(int n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int n,m,a,b,ra,rb;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        p[i] = i;
    }
    while(m--){
        scanf("%d %d",&a,&b);
        ra = find_root(a);
        rb = find_root(b);
        if(num[ra]>num[rb]){
            printf("%d\n",ra);
            p[rb] = ra;
            num[ra]+=num[rb]/2;
        }else if(num[rb]>num[ra]){
            printf("%d\n",rb);
            p[ra] = rb;
            num[rb]+=num[ra]/2;
        }else{
            if(ra == rb){
                printf("-1\n");
            }else if(ra < rb){
                printf("%d\n",ra);
                p[rb] = ra;
                num[ra]+=num[rb]/2;
            }else if(rb < ra){
                printf("%d\n",rb);
                p[ra] = rb;
                num[rb]+=num[ra]/2;
            }
        }
    }
	return 0;
}
