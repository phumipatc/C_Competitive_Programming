/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int ,int > mapp;
int main(){
    int n,u,v,w,lu,lv,ans;
    char opr;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&opr);
        if(opr == 'U'){
            scanf("%d %d %d",&u,&v,&w);
            lu = log2(u),lv = log2(v);
            while(lu!=lv){
                if(lu>lv){
                    mapp[u]+=w;
                    lu--;
                    u/=2;
                }else{
                    mapp[v]+=w;
                    lv--;
                    v/=2;
                }
            }
            while(u!=v){
                mapp[u]+=w;
                mapp[v]+=w;
                u/=2,v/=2;
            }
        }else{
            scanf("%d %d",&u,&v);
            lu = log2(u);
            lv = log2(v);
            ans = 0;
            while(lu!=lv){
                if(lu>lv){
                    ans+=mapp[u];
                    lu--;
                    u/=2;
                }else{
                    ans+=mapp[v];
                    lv--;
                    v/=2;
                }
            }
            while(u!=v){
                ans+=mapp[u]+mapp[v];
                u/=2,v/=2;
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}
