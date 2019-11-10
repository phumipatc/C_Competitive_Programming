/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    int n,j,i,ans=0;
    scanf("%d",&n);
    for(i=1;i<=5;i++)
        scanf("%d",&a[i]);
    if(a[1]+a[2]+a[3]+a[4]+a[5]==n){
        printf("%d %d %d %d %d",a[1],a[2],a[3],a[4],a[5]);
        return 0;
    }
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            if(i!=j)
                ans+=a[j];
        }
        if(ans==n){
            a[i]=0;
            printf("%d %d %d %d %d ",a[1],a[2],a[3],a[4],a[5]);
            return 0;
        }
        ans=0;
    }
    printf("-1");
return 0;
}
