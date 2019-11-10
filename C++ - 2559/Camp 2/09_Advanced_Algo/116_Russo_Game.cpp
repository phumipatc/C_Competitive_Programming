/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n,i,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=n-2;i>=0;i--){
        if(a[i]>=a[i+1]){
            ans+=abs(a[i]-(a[i+1]-1));
            a[i]=a[i+1]-1;
        }
    }
    printf("%d\n",ans);
return 0;
}
