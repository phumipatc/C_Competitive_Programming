/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A a[15001];
int mark[15001];
int main(){
    int n,k,minn,node;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(int i=0;i<n;i++)    mark[i]=1e9;
    for(int i=0;i<n-1;i++){
        minn=1e9;
        for(int j=i+1;j<n;j++){
            mark[j]=min(mark[j],abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            if(minn>mark[j]){
                minn=mark[j];
                node=j;
            }
        }
        swap(mark[i+1],mark[node]);
        swap(a[i+1],a[node]);
    }
    sort(mark,mark+n);
    int ans=0;
    for(int i=0;i<n-k;i++)  ans+=mark[i];
    printf("%d\n",ans);
    return 0;
}
/*
5 2
2 9
9 7
14 2
12 9
16 4
*/
