/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[46000]={1};
int main(){
    int n,w,i,sum=0,dif,mindif,ans1,ans2;
    scanf(" %d",&n);
    if(n==1){
        scanf("%d",&w);
        printf("0 %d\n",w);
        return 0;
    }
    while(n--){
        scanf(" %d",&w);
        for(i=45000;i>=w;i--)
            if(a[i-w]==1)
                a[i]=1;
        sum+=w;
    }
    mindif=sum;
    for(i=0;i<=sum;i++){
        if(a[i]==1){
            dif=abs(sum-2*i);
            if(dif<mindif){
                mindif=dif;
                ans1=i;
                ans2=sum-i;
            }
        }
    }
    if(ans1>ans2)
        swap(ans1,ans2);
    printf("%d %d\n",ans1,ans2);
return 0;
}
