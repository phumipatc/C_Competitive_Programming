#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A a[200200];
int ans[200200],countt[200200];
int main(){
    int n,l,num,minn;
    scanf("%d %d",&n,&l);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        a[i].x++,a[i].y++;
    }
    for(int j=1;j<=l+1;j++){
        minn = 1e9;
        for(int i=1;i<=n;i++){
            if(minn>abs(a[i].x-j)+abs(a[i].y-1)+i){
                minn = abs(a[i].x-j)+abs(a[i].y-1)+i;
                num = i;
            }
        }
        ans[j] = num;
    }
    for(int j = 1 ; j <= l+1 ; j++) countt[ans[j]]++;
    for(int j = 1 ; j <= n ; j++)
        printf("%d\n",countt[j]);
}
