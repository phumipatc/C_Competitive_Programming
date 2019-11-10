/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200];
int main(){
    int n,q,i,j,num;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(i=2;i<=n;i++){
        a[i]=a[i]+a[i-1];
    }
    while(q--){
        scanf("%d",&num);
        for(i=1;i<=n;i++){
            if(a[i]>num){
                printf("%d\n",i-1);
                break;
            }
        }
    }
    return 0;
}
