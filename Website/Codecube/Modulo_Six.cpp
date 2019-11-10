/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[100010];
int main(){
    int n,s,left,idx = 1;
    scanf("%d %d",&n,&s);
    left = s;
    if(s%3!=0 || 9*n<s || (n == 1 && s!=6)){
        printf("-1\n");
        return 0;
    }
    if(n == 1){
        printf("6\n");
        return 0;
    }
    while(left>=9)
        ans[idx++] = 9,left-=9;
    ans[idx] = left;
    if(left%2 == 0){
        for(int i=1;i<=n;i++)
            printf("%d",ans[i]);
    }else{
        if(idx!=1)  ans[1]--,ans[idx]++;
        for(int i=1;i<=n;i++)
            printf("%d",ans[i]);
    }
    return 0;
}
