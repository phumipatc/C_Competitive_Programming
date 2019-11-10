/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int ch[100001],a[100001];
int main()
{
    int x,y,z,i,l,h,ans=0;
    scanf("%d %d %d",&x,&y,&z);
    for(i=0;i<x;i++){
        scanf("%d %d",&l,&h);
        if(!a[h])
            a[h]=l;
    }
    while(a[z]){
        if(ch[z]){
            printf("-1\n");
            return 0;
        }
        ch[z]=1;
        z=a[z];
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
