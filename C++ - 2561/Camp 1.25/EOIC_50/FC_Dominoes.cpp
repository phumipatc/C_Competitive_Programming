/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,h;
};
A a[100001];
int main(){
    int n,maxx,now,countt,st,ans,minn,direct;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++)
        scanf("%d %d",&a[i].idx,&a[i].h);
    //Left To Right
    maxx = a[1].idx + a[1].h;
    countt = st = now = 1;
    for(int i=2 ; i<=n ; i++){
        if(maxx>a[i].idx){
            countt++;
            maxx = max(maxx,a[i].idx+a[i].h);
        }else{
            if(countt>ans)
                st = now,ans = countt,direct = 1;
            now = i;
            maxx = a[i].idx+a[i].h;
            countt = 1;
        }
    }
    if(countt>ans)
        st = now,ans = countt,direct = 1;
    //Right To Left
    minn = a[n].idx-a[n].h;
    countt = 1;
    now = n;
    for(int i=n-1;i>=1;i--){
        if(minn<a[i].idx){
            countt++;
            minn=min(minn,a[i].idx-a[i].h);
        }else{
            if(countt>ans)
                st = now,ans = countt,direct = 2;
            else if(countt==ans && now<st)
                st = now,direct = 2;
            else if(countt==ans && now==st && direct==1)
                st = now,direct = 2;
            now = i;
            minn = a[i].idx-a[i].h;
            countt = 1;
        }
    }
    if(countt>ans)
        st = now,ans = countt,direct = 2;
    else if(countt==ans && countt<st)
        st = now,direct = 2;
    else if(countt==ans && countt==st && direct==1)
        st = now,direct = 2;
    if(direct==1)   printf("%d R\n",st);
    else            printf("%d L\n",st);
    return 0;
}
