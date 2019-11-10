/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9901
using namespace std;
int countt[1005],ans[1005],a[1005];
int main(){
    int q,n,m,idx,anss;
    scanf("%d",&q);
    while(q--){
        anss=0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&countt[i]);
            if(i>0)
                countt[i]+=countt[i-1];
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            idx=lower_bound(countt,countt+n,a[i])-countt+1;
            ans[i]=idx;
        }
        if(idx!=n){
            m++;
            ans[m] = n;
            a[m] = countt[n-1];
        }
        int last;
        if(ans[1] == 1) last = a[1]-1;
        else            last = 1;
        for(int i=1;i<=m;i++){
            while(ans[i] == ans[i+1])   i++;
            anss+=a[i]-last-1;
            anss%=MOD;
            last=a[i];
//            printf("[%d] [%d]\n",anss,last);
        }
        printf("%d\n",anss*2);
    }
    return 0;
}
