/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    long long w,v,d,type,ch;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
struct B
{
    long long ww,vv,dd,xx,typee,chh;
    bool operator<(const B&o)const{
        return dd>o.dd;
    }
};
long long a[300000];
priority_queue<A> heap1;
priority_queue<B> heap2;
int main()
{
    A temp;
    B tempp;
    long long n,m,i,opr,ty,wr,vr,dr,xr,j,nn,mm;
    scanf("%lld %lld",&n,&m);
    for(i=1; i<=n+m; i++){
        scanf("%lld",&opr);
        if(opr==1){
            scanf("%lld",&ty);
            if(ty==1){
                scanf("%lld %lld",&temp.w,&temp.v);
                temp.type=1;
                heap1.push(temp);
            }
            if(ty==2){
                scanf("%lld %lld %lld",&temp.w,&temp.v,&temp.d);
                temp.type=2;
                heap1.push(temp);
            }
            if(ty==3){
                scanf("%lld %lld %lld %lld",&wr,&vr,&dr,&xr);
                temp.w=tempp.ww=wr;
                temp.v=tempp.vv=vr;
                temp.type=tempp.typee=3;
                temp.d=tempp.dd=dr;
                tempp.xx=xr;
                temp.ch=i,tempp.chh=i;
                heap1.push(temp),heap2.push(tempp);
            }
        }
        if(opr==2){
            while(!heap2.empty()){
                tempp=heap2.top();
                if(a[tempp.chh]==1){
                    heap2.pop();
                    continue;
                }
                if(tempp.dd<i&&a[tempp.chh]!=1){
                    tempp.ww=tempp.xx;
                    temp.w=tempp.ww;
                    temp.v=tempp.vv;
                    temp.d=300000;
                    temp.type=3;
                    temp.ch=tempp.chh;
                    heap1.push(temp);
                    heap2.pop();
                    //printf("y");
                    continue;
                }
                if(tempp.dd>=i)
                    break;
            }
            while(1){
                if(heap1.empty()){
                    printf("0\n");
                    break;
                }
                temp=heap1.top();
                heap1.pop();
                if((temp.type==2||temp.type==3)&&temp.d<i)
                    continue;
                if(temp.type==3&&a[temp.ch]==1)
                    continue;
                if(temp.type==1||temp.type==2){
                    printf("%lld\n",temp.v);
                    break;
                }
                if(temp.type==3&&a[temp.ch]!=1)
                {
                    printf("%lld\n",temp.v);
                    a[temp.ch]=1;
                    break;
                }
            }
        }
    }
    return 0;
}
/*
5 4
1 1 10 20
1 2 30 10 3
2
2
1 3 40 20 7 5
1 1 30 30
1 2 25 50 7
2
2

*/
