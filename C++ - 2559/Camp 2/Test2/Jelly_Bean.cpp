/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1200],box[1200];
int main(){
    int n,m,i,j,q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++)
            mic[i]=1<<25;
        for(i=0;i<n;i++){
            scanf("%d %d",&a,&b);
            box[i]=a*b;
        }
        for(i=1;i<=m;i++){
            for(j=0;j<n;j++)
                mic[i]=min(mic[i-box[j]]+1,mic[i]);
        }
        printf("%d\n",mic[m]);
    }
return 0;
}
