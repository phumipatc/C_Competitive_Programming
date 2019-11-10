/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int x[100100],y[100100];
int main(){
    int n,k,i,j,max=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    for(i=0;i<n;i++){
        j=upper_bound(x,x+n,x[i]+k-1)-x;
        if(j-i>max)
            max=j-i;
    }
    for(i=0;i<n;i++){
        j=upper_bound(y,y+n,y[i]+k-1)-y;
        if(j-i>max)
            max=j-i;
    }
    printf("%d\n",max);
return 0;
}
