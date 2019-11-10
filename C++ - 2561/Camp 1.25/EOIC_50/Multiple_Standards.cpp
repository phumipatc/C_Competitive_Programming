/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp[100100];
int countt[100100];
int main(){
    int n,m,num,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&num,&v);
        if(mapp[num][v])    continue;
        mapp[num][v] = 1;
        countt[num]++;
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",i,countt[i]);
	return 0;
}
