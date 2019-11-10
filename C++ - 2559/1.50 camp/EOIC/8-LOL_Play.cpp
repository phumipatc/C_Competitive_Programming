/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[60000],b[60000];
int main(){
    int n,i,j,k=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    sort(a,a+n,greater<int>());
    sort(b,b+n,greater<int>());
    for(i=0;i<n;i++){
        for(j=k;j<n;j++){
            if(a[i]>b[j]){
                ans+=a[i];
                k=j+1;
                break;
            }
        }
    }
    printf("%d\n",ans);
return 0;
}
