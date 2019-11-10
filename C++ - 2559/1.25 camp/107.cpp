/*
    TASK:Codnan
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int a[101000];
int main()
{
    int i,n,k,m;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=0;i<k;i++){
        scanf("%d",&m);
        printf("%d\n",upper_bound(a+1,a+n+1,m)-a-1);
    }
return 0;
}
