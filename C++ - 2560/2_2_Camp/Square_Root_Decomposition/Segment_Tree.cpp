/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],cluster[400];
int main(){
    int n,q,st,en,ans;
    char opr;
    scanf("%d %d",&n,&q);
    int len=(int)sqrt(n);
    while(q--){
        ans=-1e9;
        scanf(" %c %d %d",&opr,&st,&en);
        st--;
        if(opr=='U'){
            a[st]=en;
            cluster[st/len]=-1e9;
            for(int i=st/len*len;i<min(n,st/len*len+len);i++)
                cluster[st/len]=max(cluster[st/len],a[i]);
        }else{
            en--;
            for(int i=st;i<=en;){
                if(i%len==0 && i+len-1<=en){
                    ans=max(ans,cluster[i/len]);
                    i+=len;
                }else{
                    ans=max(ans,a[i]);
                    i++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
5 4
U 1 -14
U 1 -1
P 2 2
P 3 5

6 7
U 5 280
U 1 7
P 1 2
P 3 5
U 4 -873860809
U 2 -392
P 1 1
*/
