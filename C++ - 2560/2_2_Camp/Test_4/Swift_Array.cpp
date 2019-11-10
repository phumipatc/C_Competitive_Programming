/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ar[100100],cluster[100100];
int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    int len=(int)sqrt(n);
    while(t--){
        char opr;
        int a,b;
        scanf(" %c %d %d",&opr,&a,&b);
        a--;
        if(opr=='U'){
            ar[a]=b;
            cluster[a/len]=-1e9;
            for(int i=(a/len)*len;i<min(n,((a/len)*len)+len);i++)
                cluster[a/len]=max(cluster[a/len],ar[i]);
        }else{
            b--;
            int ans=-1;
            for(int i=a;i<=b;){
                if(i%len==0 && i+len-1<=b){
                    ans=max(ans,cluster[i/len]);
                    i+=len;
                }else{
                    ans=max(ans,ar[i]);
                    i++;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
