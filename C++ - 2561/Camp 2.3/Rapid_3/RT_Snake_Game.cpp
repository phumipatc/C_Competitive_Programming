/*
    TASK:RT_Snake Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int r[1010],l[1010],countt[1010];
int main(){
    int n,m,i,j,b,all=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        l[i] = 1e9;
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'J'){
                countt[i]++;
                l[i] = min(l[i],j);
                r[i] = max(r[i],j);
            }
        }
        if(l[i] == 1e9) l[i] = 0;
        all+=countt[i];
    }
    int state = 1,ans = 0,last = 1;
    for(i=n;i>=0;i--){
        if(!all){
            printf("%d\n",ans);
            break;
        }
        all-=countt[i];
        if(i == n){
            if(!countt[i])  r[i] = 1,l[i] = 1,last = 1;
            else            last = r[i],ans+=r[i]-1;
            state^=1;
        }
        else if(!countt[i]){
            ans++;
            state^=1;
        }
        else if(state%2)
        {
            ans+=abs(l[i]-last)+r[i]-l[i]+1;
            state^=1;
            last = r[i];
        }
        else
        {
            ans+=abs(r[i]-last)+r[i]-l[i]+1;
            state^=1;
            last = l[i];
        }
    }
    return 0;
}
/*
5 5
...J.
.....
J..J.
J....
Z....
*/
