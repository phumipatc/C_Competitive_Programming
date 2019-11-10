/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(a[j]>a[j+1]){
                for(;j<=n;j++)
                    a[j]=a[j+1];
                break;
            }
        }
        n--;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}
