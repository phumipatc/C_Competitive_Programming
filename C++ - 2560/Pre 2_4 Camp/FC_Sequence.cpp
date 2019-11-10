/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[4][4];
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<4;i++){
        for(long long j=0;j<4;j++){
            for(long long k=0;k<4;k++){
                temp.a[i][j]+=(a.a[i][k]*b.a[k][j]);
                temp.a[i][j]%=2553;
            }
        }
    }
    return temp;
}
A p[12][130],ans,multiply;
int main(){
    long long n,ch,countt,a,b,c,d,e,f,g,h,q;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g,&h,&q);
    p[0][1]={{0,1,0,0,0,0,1,0,0,0,0,1,h,g,f,e}};
    for(long long i=2;i<128;i++)  p[0][i]=multi(p[0][i-1],p[0][1]);
    for(long long i=1;i<=10;i++){
        p[i][1]=multi(p[i-1][127],p[i-1][1]);
        for(long long j=2;j<=128;j++)
            p[i][j]=multi(p[i][1],p[i][j-1]);
    }
    multiply={{a,0,0,0,b,0,0,0,c,0,0,0,d,0,0,0}};
    while(q--){
        scanf("%lld",&n);
        if(n<=4){
            if(n==1)    printf("%lld\n",a);
            if(n==2)    printf("%lld\n",b);
            if(n==3)    printf("%lld\n",c);
            if(n==4)    printf("%lld\n",d);
            continue;
        }
        n--;
        ch=1;
        countt=0;
        while(n>0){
            long long temp=n%128;
            n/=128;
            if(temp){
                if(ch){
                    ch=0;
                    ans=p[countt][temp];
                }else
                    ans=multi(ans,p[countt][temp]);
            }
            countt++;
        }
        ans=multi(ans,multiply);
        printf("%lld\n",ans.a[0][0]);
    }
    return 0;
}
