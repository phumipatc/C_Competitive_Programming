/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int pos[1000100];
int main(){
    int n,m,k,l;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=0;i<n;i++)
        scanf("%d",&pos[i]);
    while(k--){
        int ans=0,jump=0,num;
        for(int i=0;i<m;i++){
            scanf("%d",&num);
            int idx=lower_bound(pos+jump,pos+n,num-l)-pos;
            int idx2=upper_bound(pos+jump,pos+n,num+l)-pos;
            jump=idx2;
            ans+=idx2-idx;
        }
        printf("%d\n",ans);
    }
    return 0;
}
