/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int z[100100];
int main()
{
    int n,q,i,a,b,ans;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&z[i]);
    }
    for(i=2;i<=n;i++){
        z[i]=z[i-1]^z[i];
    }
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d\n",z[a-1]^z[b]);
    }
	return 0;
}
