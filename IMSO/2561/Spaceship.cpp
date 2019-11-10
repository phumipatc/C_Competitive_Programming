/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,z,m,k,c;
};
A shop[12];
int minn = 1e9,n,M,mark[12];
void travel(int x,int y,int z,int m,int k,int c,int sum){
    A nextt;
    for(int i=0;i<M;i++){
        if(!mark[i]){
            mark[i] = 1;
            nextt = shop[i];
            nextt.m+=m;
            nextt.k+=k;
            nextt.c+=c;
            int nsum = sum+((x-nextt.x)*(x-nextt.x)+(y-nextt.y)*(y-nextt.y)+(z-nextt.z)*(z-nextt.z));
            if(nextt.m>=n && nextt.k>=n && nextt.c>=n){
                minn = min(minn,nsum);
                mark[i] = 0;
                continue;
            }
            travel(nextt.x,nextt.y,nextt.z,nextt.m,nextt.k,nextt.c,nsum);
            mark[i] = 0;
        }
    }
}
int main(){
    int x,y,z;
    scanf("%d %d %d %d %d",&n,&x,&y,&z,&M);
    for(int i=0;i<M;i++)
        scanf("%d %d %d %d %d %d",&shop[i].x,&shop[i].y,&shop[i].z,&shop[i].m,&shop[i].k,&shop[i].c);
    travel(x,y,z,0,0,0,0);
    printf("%d\n",minn);
    return 0;
}
