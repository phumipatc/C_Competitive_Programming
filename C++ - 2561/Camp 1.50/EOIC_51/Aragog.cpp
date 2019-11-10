/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int q,n,m,ans;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        printf("Case %d: ",i);
        scanf("%d %d",&n,&m);
        for(int j=0;j<n;j++)
            scanf("%d",&a[j]);
        ans = 0;
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(a[j]>a[k])
                    ans++;
        if(ans<=m && (m-ans)%2 == 0)    printf("YES\n");
        else                            printf("NO\n");
    }
	return 0;
}
