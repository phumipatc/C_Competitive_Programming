/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <bits/stdc++.h>
using namespace std;
long long a[100100][2];
int main()
{
    long long n,i,now,ma,sum,ans=0,cou,type=2,mi,st,stnow;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld %lld",&a[i][0],&a[i][1]);
    //L->R
    now = a[1][0]+a[1][1];
    ma = now;
    cou=1; st=1;
    stnow=1;
    for(i=2;i<=n;i++){
        if(ma>a[i][0]){
            cou++;
            now = a[i][0]+a[i][1];
            ma = max(ma,now);
        }else{
            if(cou>ans){
                st = stnow; ans=cou; type=1;
            }
            stnow=i;
            ma = a[i][0]+a[i][1],cou=1;
        }
    }
    if(cou>ans){
        st = stnow; ans=cou; type=1;
    }
    //R->L
    now = a[n][0]-a[n][1];
    mi = now;
    cou=1; stnow=n;
    for(i=n-1;i>=1;i--){
        if(mi<a[i][0]){
            cou++;
            now = a[i][0]-a[i][1];
            mi = min(mi,now);
        }
        else{
            if(cou>ans){
                st = stnow; ans=cou; type=2;
            }
            else if(cou==ans && stnow<st){
                st = stnow; ans=cou; type=2;
            }
            else if(cou==ans && stnow==st && type==1){
                st = stnow; ans=cou; type=2;
            }
            stnow=i;
            mi = a[i][0]-a[i][1],cou=1;
        }
    }
    if(cou>ans){
        st = stnow; ans=cou; type=2;
    }
    else if(cou==ans && cou<st){
        st = stnow; ans=cou; type=2;
    }
    else if(cou==ans && cou==st && type==1){
        st = stnow; ans=cou; type=2;
    }
    printf("%lld ",st);
    printf((type==1)?"R":"L");
    return 0;
}
/*
5 1 1 3 3 5 4 7 15 10 3
*/
