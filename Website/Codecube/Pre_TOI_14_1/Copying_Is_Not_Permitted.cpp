/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct info{
    long long from,to,value;
    bool operator<(const info &o)const{
        if(value < o.value)         return true;
        else if(value > o.value)    return false;
        else                        return true;
    }
};
struct infocheck{
    long long a,b;
};
long long root[40040];
info path[50050];
infocheck check[50050];
long long findroot(long long e){
    if(root[e] == e)    return e;
    else                return root[e] = findroot(root[e]);
}
int main(){
    long long n,m,chn;
    scanf("%lld %lld %lld",&n,&m,&chn);
    for(long long i = 1 ; i <= m ; i++)
        scanf("%lld %lld %lld",&path[i].from,&path[i].to,&path[i].value);
    for(long long i = 1 ; i <= chn ; i++)
        scanf("%lld %lld",&check[i].a,&check[i].b);
    for(long long i = 1 ;i <= n ; i++)
        root[i] = i;
    sort(path+1,path+1+m);
    long long a,b,v;
    long long roota,rootb;
    long long rootcha,rootchb;
    //check all
    for(long long i = 1 ; i <= m ; i++){
        a = path[i].from;
        b = path[i].to;
        v = path[i].value;
        roota = findroot(root[a]);
        rootb = findroot(root[b]);
        if(roota != rootb)
            root[rootb] = roota;
    }
    long long ch = 0;
    for(long long i = 1 ; i <= chn ; i++){
        rootcha = findroot(root[check[i].a]);
        rootchb = findroot(root[check[i].b]);
        if(rootcha == rootchb)
            ch = 1;
    }
    if(ch==0){
        printf("-1");
        return 0;
    }
    long long left = 0;
    long long right = 1e9;
    long long mid;
    while(left < right){
        mid = (left+right)/2;
        for(long long i = 1 ; i <= n ; i++)
            root[i] = i;
        for(long long i = 1 ; i <= m ; i++){
            a = path[i].from;
            b = path[i].to;
            v = path[i].value;
            if(path[i].value <= mid){
                roota = findroot(root[a]);
                rootb = findroot(root[b]);
                if(roota != rootb)
                    root[rootb] = roota;
            }else
                break;
        }
        int moveR = 0;
        for(long long i = 1 ; i <= chn ; i++){
            rootcha = findroot(root[check[i].a]);
            rootchb = findroot(root[check[i].b]);
            if(rootcha == rootchb){
                moveR = 1;
                break;
            }
        }
        if(moveR == 1)
            right = mid;
        else
            left = mid+1;
    }
    printf("%lld",left);
}

