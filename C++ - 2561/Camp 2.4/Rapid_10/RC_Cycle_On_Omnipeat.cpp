/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],comp[100010],countt[100010];
int main(){
    int q,n,now,ch,idx,maxx;
    scanf("%d",&q);
    while(q--){
        memset(countt,0,sizeof countt);
        scanf("%d",&n);
        maxx = 1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            comp[maxx++] = a[i];
        }
        sort(a+1,a+n+1);
        sort(comp+1,comp+maxx);
        for(int i=1;i<maxx;i++){
            idx = lower_bound(comp+1,comp+maxx,a[i])-comp;
            countt[idx]++;
        }
        idx = lower_bound(comp+1,comp+maxx,a[1])-comp;
        countt[idx]--;
        n--;
        now = a[1];
        ch = 1;
        while(n--){
            idx = lower_bound(comp+1,comp+maxx,now+1)-comp;
            if(comp[idx] == now+1 && countt[idx]){
                countt[idx]--;
                now++;
                continue;
            }
            idx = lower_bound(comp+1,comp+maxx,now-1)-comp;
            if(comp[idx] == now-1 && countt[idx]){
                countt[idx]--;
                now--;
                continue;
            }
            ch = 0;
            break;
        }
        if(ch && abs(now-a[1]) == 1)    printf("YES\n");
        else                            printf("NO\n");
    }
	return 0;
}