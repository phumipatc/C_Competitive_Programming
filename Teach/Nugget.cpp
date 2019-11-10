/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool mark[1000010];
int nugget[3] = {6,9,20};
int main(){
    int n,countt = 0;
    scanf("%d",&n);
    mark[0] = true;
    for(int i=0;i<3;i++)
        for(int j=nugget[i];j<=n;j++)
            if(mark[j-nugget[i]])
                mark[j] = true;
    for(int i=1;i<=n;i++)
        if(mark[i])
            countt++;
    printf("%d\n",countt);
    return 0;
}
