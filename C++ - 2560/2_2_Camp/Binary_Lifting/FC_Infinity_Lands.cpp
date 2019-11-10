/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
int main(){
    int m,i,u,v,w,lvu,lvv;
    scanf("%d",&m);
    while(m--){
        char opr;
        scanf(" %c",&opr);
        if(opr=='U'){
            scanf("%d %d %d",&u,&v,&w);
            lvu=log2(u);
            lvv=log2(v);
            //Different level
            while(lvu!=lvv){
                if(lvu>lvv){
                    mapp[u]+=w;
                    lvu--;
                    u/=2;
                }else{
                    mapp[v]+=w;
                    lvv--;
                    v/=2;
                }
            }
            //Same Level
            while(u!=v){
                mapp[u]+=w;
                mapp[v]+=w;
                u/=2;
                v/=2;
            }
        }else if(opr=='Q'){
            scanf("%d %d",&u,&v);
            int ans=0;
            lvu=log2(u);
            lvv=log2(v);
            //Different level
            while(lvu!=lvv){
                if(lvu>lvv){
                    ans+=mapp[u];
                    lvu--;
                    u/=2;
                }else{
                    ans+=mapp[v];
                    lvv--;
                    v/=2;
                }
            }
            //Same Level
            while(u!=v){
                ans+=mapp[u]+mapp[v];
                u/=2;
                v/=2;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
7
U 3 4 30
U 4 1 2
U 3 6 8
Q 4 3
U 6 1 40
Q 3 7
Q 2 4
*/
