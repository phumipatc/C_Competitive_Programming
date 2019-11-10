#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int i,p,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d %d",&p,&w);
        for(j=0;j<w;j++)
            mic[i][j] = mic[i-1][j];
        for(j=w;j<=m;j++)
            mic[i][j] = max(mic[i-1][j],p+mic[i-1][j-w]);
    }
    printf("%d\n",mic[n][m]);
    return 0;
}
