/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long p,par,child;
};
A fam[10100];
long long find_root(long long num){
    if(num == fam[num].par) return num;
    else                    return fam[num].par = find_root(fam[num].par);
}
int main(){
    long long n,d,a,b,ra,rb;
    scanf("%lld %lld",&n,&d);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&a,&b);
        fam[i].p = a*b;
        fam[i].par = i;
        fam[i].child = 0;
    }
    for(long long i=1;i<=d;i++){
        printf("Day: %lld\n",i);
        scanf("%lld %lld",&a,&b);
        ra = find_root(a);
        rb = find_root(b);
        if(ra == rb){
            printf("Family don\'t need to make war\n");
        }else if(fam[ra].p>fam[rb].p){
            printf("Winner Family %lld\n",ra);
            fam[ra].p+=fam[rb].p;
            fam[ra].child+=fam[rb].child+1;
            fam[rb].par = ra;
        }else if(fam[rb].p>fam[ra].p){
            printf("Winner Family %lld\n",rb);
            fam[rb].p+=fam[ra].p;
            fam[rb].child+=fam[ra].child+1;
            fam[ra].par = rb;
        }else if(fam[ra].child>fam[rb].child){
            printf("Winner Family %lld\n",ra);
            fam[ra].p+=fam[rb].p;
            fam[ra].child+=fam[rb].child+1;
            fam[rb].par = ra;
        }else if(fam[rb].child>fam[ra].child){
            printf("Winner Family %lld\n",ra);
            fam[rb].p+=fam[ra].p;
            fam[rb].child+=fam[ra].child+1;
            fam[ra].par = rb;
        }else{
            printf("Draw\n");
        }
    }
	return 0;
}
