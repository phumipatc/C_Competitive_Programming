/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
//c == 1 is werewolf
//c == 2 is villager
int a[100010],col[100010],in[100010];
void paint(int now,int c){
    if(col[now])    return ;
    col[now] = c;
    in[a[now]]--;
    if(in[a[now]] == 0 || c == 1)
        paint(a[now],3-c);
}
int main(){
    int q,n,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ans = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            in[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i])   continue;
            paint(i,1);
        }
        for(int i=1;i<=n;i++){
            if(col[i])  continue;
            paint(i,2);
        }
        for(int i=1;i<=n;i++){
            if(col[i] == 2)
                ans++;
        }
        printf("%d\n",ans);
        memset(in,0,sizeof in);
        memset(col,0,sizeof col);
    }
	return 0;
}
