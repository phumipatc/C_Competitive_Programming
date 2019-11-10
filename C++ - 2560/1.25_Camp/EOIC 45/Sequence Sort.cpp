/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int m;
struct A{
    int b[11];
    bool operator<(const A&o)const{
        for(int i=0;i<m;i++){
            if(b[i]<o.b[i]) return true;
            else if(b[i]>o.b[i]) return false;
            else continue;
        }
    }
};
A a[100100];
int main(){
    int n,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            scanf("%d",&a[i].b[j]);
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",a[i].b[j]);
        }
        printf("\n");
    }
    return 0;
}
