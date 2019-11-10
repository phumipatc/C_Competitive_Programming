/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300010],l[300010],r[300010],mark[300010];
char tes[300010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf(" %s",tes+1);
    while(a[k+1] == a[k])   k++;
    for(int i=2;i<=n;i++){
        if(a[i]>=a[i-1]){
            l[i] = l[i-1]+1;
            if(tes[i-1] == 'T') tes[i] = 'T';
        }
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]>=a[i+1]){
            r[i] = r[i+1]+1;
            if(tes[i+1] == 'T') tes[i] = 'T';
        }
    }
    int countt = 0,maxx = 0;
    for(int i=1;i<=n;i++){
        if(tes[i] == 'T')   countt++;
        else                maxx = max(maxx,max(l[i],r[i])+1);
    }
    int ans;
    if(tes[k] == 'T')   ans = min(n,countt+maxx);
    else                ans = max(l[k],r[k])+1;
    printf("%d\n",ans);
	return 0;
}
