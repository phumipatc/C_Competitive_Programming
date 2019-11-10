/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[50][50],a[50],b[50],n;
int matrix(int st,int en){
    int i;
    if(mic[st][en])
        return mic[st][en];
    if(st==en)
        return 0;
    mic[st][en]=1<<25;
    for(i=st;i<en;i++){
        mic[st][en]=min(mic[st][en],matrix(st,i)+matrix(i+1,en)+a[st]*b[i]*b[en]);
    }
    return mic[st][en];
}
int main(){
    int i,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    ans=matrix(1,n);
    printf("%d\n",ans);
return 0;
}
