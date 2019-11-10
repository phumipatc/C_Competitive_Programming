/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int l[500010],r[500010];
int main(){
    int n,k,a,b,now;
    char opr;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n;i++)
        l[i] = i-1,r[i] = i+1;
    while(k--){
        scanf(" %c %d %d",&opr,&a,&b);
        if(opr == 'A'){
            r[l[a]] = r[a];
            l[r[a]] = l[a];
            r[l[b]] = a;
            l[a] = l[b];
            r[a] = b;
            l[b] = a;
        }else{
            r[l[a]] = r[a];
            l[r[a]] = l[a];
            l[r[b]] = a;
            r[a] = r[b];
            r[b] = a;
            l[a] = b;
        }
    }
    now = r[0];
    for(int i=1;i<=n;i++){
        printf("%d ",now);
        now = r[now];
    }
	return 0;
}
