/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,aa,bb,cc,dd,ee,na,nb,nc,nd,ne;
int main()
{
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    aa=a,bb=b,cc=c,dd=d,ee=e;
    if(e>=50){                              //Greedy - Use 50 Cent
        nd=e/50;
        if(nd<=d)   e%=50,d-=nd;
        else        nd=d,d=0,e=e-(nd*50);
    }
    if(e>=20){
        nc=e/20;
        if(nc<=c)   e%=20,c-=nc;
        else        nc=c,c=0,e=e-(nc*20);
    }
    if(e>=10){
        nb=e/10;
        if(nb<=b)   e%=10,b-=nb;
        else        nb=b,b=0,e=e-(nb*10);
    }
    na=e/5;
    if(na<=a && na*5+nb*10+nc*20+nd*50==ee){
        e%=5,a-=na;
        printf("%d %d %d %d %d",na,nb,nc,nd,na+nb+nc+nd);
        return 0;
    }
    a=aa,b=bb,c=cc,d=dd,e=ee,na=nb=nc=nd=ne=0;          //Greedy - Not use 50 Cent
    if(e>=100){
        nd=e/100;
        nd*=2;
        if(nd<=d)   e%=100,d-=nd;
        else        nd=d,d=0,e=e-(nd*100);
    }
    if(e>=20){
        nc=e/20;
        if(nc<=c)   e%=20,c-=nc;
        else        nc=c,c=0,e=e-(nc*20);
    }
    if(e>=10){
        nb=e/10;
        if(nb<=b)   e%=10,b-=nb;
        else        nb=b,b=0,e=e-(nb*10);
    }
    na=e/5;
    if(na<=a && na*5+nb*10+nc*20+nd*50==ee){
        e%=5,a-=na;
        printf("%d %d %d %d %d",na,nb,nc,nd,na+nb+nc+nd);
        return 0;
    }
    printf("-1\n");
    return 0;
}
