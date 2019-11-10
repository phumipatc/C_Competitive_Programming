/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int find_root(int n){
    if(p[n]==n) return n;
    else        return p[n]=find_root(p[n]);
}
int main(){
    int n,q,a,b;
    char opr;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)   p[i]=i;
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        int ra=find_root(a);
        int rb=find_root(b);
        if(opr=='c'){
            if(ra!=rb)
                p[rb]=ra;
        }else{
            if(ra==rb)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
