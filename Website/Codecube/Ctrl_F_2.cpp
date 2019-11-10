/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int KMP[1000010];
int main(){
    int n,m,i,j = 0,ans = 0;
    scanf("%d %d %s %s",&n,&m,a+1,b+1);
    for(i=2;i<=m;i++){
        while(j>0 && b[j+1]!=b[i])  j = KMP[j];
        if(b[j+1] == b[i])  j++;
        KMP[i] = j;
    }
    j = 0;
    for(int i=1;i<=n;i++){
        while(j>0 && b[j+1]!=a[i])  j = KMP[j];
        if(b[j+1] == a[i])  j++;
        if(j == m)  ans++;
    }
    printf("%d\n",ans);
	return 0;
}
