/*
    TASK:Influenza
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
int main(){
    int n,i,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    for(i=0;i<n;i++){
        ans=max(ans,min(a[i],b[n-1-i]));
    }
    printf("%d\n",ans);
return 0;
}
