/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int i,n,q,ask;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(i=0;i<q;i++){
        scanf("%d",&ask);
        printf("%d",upper_bound(a,a+n,ask)-a);
    }
return 0;
}
