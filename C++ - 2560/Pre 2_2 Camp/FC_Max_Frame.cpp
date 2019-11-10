/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,value;
};
int a[1100][1100],ans[1100][1100];
deque< A> q;
int main(){
    int r,c,m,n,i,j;
    scanf("%d %d %d %d",&r,&c,&m,&n);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=r;i++){
        while(!q.empty())   q.pop_back();
        for(j=1;j<=c+n;j++){
            while(!q.empty() && q.front().idx<j-(2*n))  q.pop_front();
            while(!q.empty() && q.back().value<=a[i][j])    q.pop_back();
            if(j<=c)    q.push_back({j,a[i][j]});
            if(j>n)     ans[i][j-n]=q.front().value;
        }
    }
    for(j=1;j<=c;j++){
        while(!q.empty())   q.pop_back();
        for(i=1;i<=r+m;i++){
            while(!q.empty() && q.front().idx<i-(2*m))  q.pop_front();
            while(!q.empty() && q.back().value<=ans[i][j])    q.pop_back();
            if(i<=r)    q.push_back({i,ans[i][j]});
            if(i>m)     ans[i-m][j]=max(ans[i-m][j],q.front().value);
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
