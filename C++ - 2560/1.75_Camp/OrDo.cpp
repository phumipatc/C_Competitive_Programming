/*
	TASK: Or Do
	AUTHOR: Boss
	SCHOOL: RYW
	LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
int a[100010],b[32][100100];
int main(){
    int n,i,j,q,l,r,ans;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        for(j=0;j<31;j++){
            b[j][i]=b[j][i-1];
            if(a[i]&(1<<j)) b[j][i]++;
        }
    }
    while(q--){
        scanf("%d %d",&l,&r);
        ans=0;
        for(i=0;i<31;i++)
            if(b[i][r]>b[i][l-1])
                ans+=(1<<i);
        printf("%d\n",ans);
    }
    return 0;
}
/*
5 3 1 2 4 5 8 2 2 1 5 3 5
*/
