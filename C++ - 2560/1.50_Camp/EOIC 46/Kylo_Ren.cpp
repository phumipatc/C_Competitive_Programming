/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[1000010];
int main()
{
    int i,j;
    for(i=1;i<=1000000;i++){
        ans[i]=1;
    }
    for(i=2;i<=1000000;i++){
        for(j=i;j<=1000000;j+=i){
            ans[j]++;
        }
    }
    int q,a,b,c;
    scanf("%d",&q);
    while(q--){
        int countt=0;
        scanf("%d %d %d",&a,&b,&c);
        for(i=a;i<=b;i++){
            if(ans[i]==c)   countt++;
        }
        printf("%d\n",countt);
    }
    while(q--)
	return 0;
}
