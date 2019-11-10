/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[45100]={1};
int main(){
    int n,minn=1<<30,i,j,num,sum=0,ans1,ans2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        sum+=num;
        for(j=45000;j>=num;j--){
            if(dp[j-num])
                dp[j]=1;
        }
    }
    for(i=0;i<=sum;i++){
        if(dp[i]){
                if(abs(sum-2*i)<minn){
                    minn=abs(sum-2*i);
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
