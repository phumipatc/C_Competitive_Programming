/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[100100];
int main(){
    int n,m,q,st,en,v;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&st,&en,&v);
        qs[st]+=v;
        qs[en+1]-=v;
    }
    for(int i=1;i<=n;i++)
        qs[i]+=qs[i-1];
    while(q--){
        scanf("%d",&st);
        printf("%d\n",qs[st]);
    }
	return 0;
}
