/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010],dia1[200010],dia2[200010];
int main(){
    int n,k,a,b;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&b);
        x[a]++,y[b]++,dia1[a-b+100000]++,dia2[a+b]++;
        if(x[a] == k || y[b] == k || dia1[a-b+100000] == k || dia2[a+b] == k){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1\n");
	return 0;
}
