/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,minn,num,i,ans=0;
    scanf("%d %d",&n,&minn);
    for(i=1;i<n;i++){
        scanf("%d",&num);
        if(num-minn>ans)
            ans=num-minn;
        if(num<minn)
            minn=num;
    }
    printf("%d\n",ans);
return 0;
}
