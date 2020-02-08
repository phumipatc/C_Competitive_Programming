/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[300010][20],last[300010],lv[300010];
int main(){
    int n,u,v;
    char opr;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&opr);
        if(opr == 'a'){
            scanf("%d",&u);
            last[i] = i;
            lv[i] = lv[last[u]]+1;
            p[i][0] = last[u];
            for(int j=1;j<=18;j++)
                p[i][j] = p[p[i][j-1]][j-1];
        }else if(opr == 'b'){
            scanf("%d",&u);
            last[i] = p[last[u]][0];
            lv[i] = lv[p[last[u]][0]];
            if(last[u] == 0)    printf("-1\n");
            else                printf("%d\n",last[u]);
        }else if(opr == 'c'){
            scanf("%d %d",&u,&v);
            last[i] = u = last[u],v = last[v];
            if(lv[u]<lv[v]) swap(u,v);
            for(int i=18;i>=0;i--){
                if(lv[p[u][i]]<lv[v])   continue;
                u = p[u][i];
            }
            if(u == v){
                printf("%d\n",lv[u]);
                continue;
            }
            for(int i=18;i>=0;i--){
                if(p[u][i] == p[v][i])  continue;
                u = p[u][i],v = p[v][i];
            }
            printf("%d\n",lv[p[u][0]]);
        }
    }
	return 0;
}