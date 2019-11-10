/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100];
int main(){
    int r,c;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    int q,sti,stj,eni,enj;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
        sti++,stj++,eni++,enj++;
        printf("%d\n",a[eni][enj]-a[eni][stj-1]-a[sti-1][enj]+a[sti-1][stj-1]);
    }
    return 0;
}
