/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> a;
char b[20];
int main()
{
    int q,n,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        while(m--){
            scanf(" %s",b);
            a[b]=1;
        }
        if(a.size()==n) printf("yes\n");
        else                printf("no\n");
        a.clear();
    }
	return 0;
}
