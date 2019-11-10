/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    bool operator < (const A&o) const{
        if(u!=o.u)  return u<o.u;
        else        return v<o.v;
    }
};
A a[100100],b[100100];
char ans[10];
int main()
{
    A temp;
    int i,j,n,ch,k;
    for(k=1;k<=5;k++){
        scanf("%d",&n);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&a[i].u,&a[i].v);
            if(a[i].u>a[i].v)   swap(a[i].u,a[i].v);
        }
        sort(a,a+n-1);
        for(i=0;i<n-1;i++){
            scanf("%d %d",&b[i].u,&b[i].v);
            if(b[i].u>b[i].v)   swap(b[i].u,b[i].v);
        }
        sort(b,b+n-1);
        for(i=0,ch=1;i<n-1;i++){
//            printf("%d %d\n%d %d\n",a[i].u,a[i].v,b[i].u,b[i].v);
            if(a[i].u!=b[i].u || a[i].v!=b[i].v){
                ch=0;
                break;
            }
        }
        if(ch)  ans[k]='Y';
        else    ans[k]='N';
        for(i=0;i<n-1;i++){
            a[i].u=a[i].v=b[i].u=b[i].v=0;
        }
    }
    for(i=1;i<=5;i++)    printf("%c",ans[i]);
    return 0;
}
/*
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 4 9 1 5 6 4 3 5 7 5 7 8 2 4
9
2 4 9 4 6 4 1 4 1 5 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
2 4 6 4 1 4 1 5 9 4 3 5 7 5 7 8
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
9
9 4 3 5 7 5 7 8 2 4 6 4 1 4 1 5
1 4 9 4 1 5 2 4 6 4 3 5 7 5 7 8
4
1 2 2 3 3 4
1 2 1 3 1 4
*/
