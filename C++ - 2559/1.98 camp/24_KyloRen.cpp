/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int i,j,q,r,s,t,c;
    for(i=1;i<=1000000;i++)
        for(j=i;j<=1000000;j+=i)
            a[j]++;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&r,&s,&t);
        c=0;
        for(i=r;i<=s;i++)
            if(a[i]==t)
            c++;
        printf("%d\n",c);
    }
return 0;
}
