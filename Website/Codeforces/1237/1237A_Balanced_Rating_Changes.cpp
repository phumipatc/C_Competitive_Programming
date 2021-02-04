/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[13850],mark[13850];
int main(){
    int n,sum = 0,plus = 0,minus = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]%2){
            if(a[i]>0)  mark[i] = 1;
            else        mark[i] = -1;
        }
        a[i]/=2;
        sum+=a[i];
    }
    for(int i=1;i<=n;i++){
        if(!mark[i] || sum == 0){
            printf("%d\n",a[i]);
            continue;
        }
        if(sum<0){
            if(mark[i] == -1)   printf("%d\n",a[i]);
            else                printf("%d\n",a[i]+1),sum++;
        }else if(sum>0){
            if(mark[i] == 1)    printf("%d\n",a[i]);
            else                printf("%d\n",a[i]-1),sum--;
        }
    }
    return 0;
}