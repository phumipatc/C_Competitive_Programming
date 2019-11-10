/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxx=-1<<25,minn=1<<25,a;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&a);
        maxx=max(a,maxx);
        minn=min(a,minn);
    }
    printf("%d\n%d\n",maxx,minn);
return 0;
}
