/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[10100],mark[10100];
int root(int i){
    if(p[i]=i)  return i;
    else        return p[i]=root(p[i]);
}
int main(){
    int n,m,i,j,lang,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        p[i]=i;
        mark[i]=1;
    }
    for(i=0;i<n;i++){
        scanf("%d",&lang);
        for(j=0;j<lang;j++){
            scanf("%d",&a);
        }
    }
return 0;
}
