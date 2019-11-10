/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[300001];
int mark[300001];
int find_root(int idx){
    if(p[idx]==idx) return idx;
    else            return p[idx]=find_root(p[idx]);
}
int main(){
    int q,l;
    scanf("%d %d",&q,&l);
    for(int i=1;i<=l;i++)
        p[i]=i;
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        int ra=find_root(a);
        int rb=find_root(b);
        if(!mark[a]){
            mark[a]=1;
            printf("Yes\n");
            p[ra]=rb;
            continue;
        }
        if(!mark[b]){
            mark[b]=1;
            printf("Yes\n");
            p[rb]=ra;
            continue;
        }
        if(!mark[ra]){
            mark[ra]=1;
            printf("Yes\n");
            p[ra]=rb;
            continue;
        }
        if(!mark[rb]){
            mark[rb]=1;
            printf("Yes\n");
            p[rb]=ra;
            continue;
        }
        printf("No\n");
    }
    return 0;
}
