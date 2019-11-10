/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[120000],mic[120000];
int main(){
    int n,i,j,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mic[i]=a[i];
    }
    mic[1]=mic[2]=0;
    mic[3]=a[3];
    mic[4]=max(a[3],a[4]);
    mic[5]=max(mic[4],a[5]);
    mic[6]=max(mic[5],a[3]+a[6]);
    for(i=7;i<=n;i++){
        mic[i]=max(mic[i-1])
    }
    printf("%d",mic[n]);
return 0;
}
//12 1 2 5 4 3 0 6 1 2 7 2 1
