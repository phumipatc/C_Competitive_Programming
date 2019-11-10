/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s2,s3,s5,s7,x;
    bool operator < (const A & o)const{
        if(x != o.x)    return x < o.x;
        return s2+s3+s5+s7<o.s2+o.s3+o.s5+o.s7;
    }
};
A ar[400200];
void play(long long w,long long x,long long i,long long ty){
    ar[i].s2 = 0;
    ar[i].s3 = 0;
    ar[i].s5 = 0;
    ar[i].s7 = 0;
    if(w == 2)  ar[i].s2 = 1;
    if(w == 3)  ar[i].s3 = 1;
    if(w == 4)  ar[i].s2 = 2;
    if(w == 5)  ar[i].s5 = 1;
    if(w == 6)  ar[i].s2 = 1,ar[i].s3 = 1;
    if(w == 7)  ar[i].s7 = 1;
    if(w == 8)  ar[i].s2 = 3;
    if(w == 9)  ar[i].s3 = 2;
    if(w == 10) ar[i].s2 = 1,ar[i].s5 = 1;
    if(ty == 2){
        ar[i].s2 *= -1;
        ar[i].s3 *= -1;
        ar[i].s5 *= -1;
        ar[i].s7 *= -1;
    }
    ar[i].x = x;
}
long long ans;
int main(){
    long long m,n,v,st,en,s2,s3,s5,s7,countt=0,ma,mx=0,i;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&v,&st,&en);
        play(v,st,countt,1);
        countt++;
        play(v,en+1,countt,2);
        countt++;
    }
    sort(ar,ar+countt);
    s2 = 0;
    s3 = 0;
    s5 = 0;
    s7 = 0;
    for(i=0;i<countt-1;i++){
        s2 += ar[i].s2;
        s3 += ar[i].s3;
        s5 += ar[i].s5;
        s7 += ar[i].s7;
        ma = (s2+1)*(s3+1)*(s5+1)*(s7+1);
        if(ma > mx){
            mx = ma;
            ans = ar[i].x - ar[i+1].x;
        }
        else if(ma == mx){
            ans += ar[i].x - ar[i+1].x;
        }
    }
    printf("%lld %lld\n",mx,abs(ans));
    return 0;
}
/*
5 10
3 0 4
2 2 3
5 4 7
6 7 9
2 3 3

8 10
4 0 3
3 3 6
5 4 6
2 4 6
10 0 1
9 5 6
7 0 3
2 3 4
*/
