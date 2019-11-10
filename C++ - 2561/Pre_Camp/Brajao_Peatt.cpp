/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long num,val;
    bool operator <(const A& o) const{
        if(val!=o.val) return val<o.val;
        else return num<o.num;
    }
};
A x[100100],y[100100];
long long xnum[100100],xval[100100],ynum[100100],yval[100100];
int main(){
    int yy,xx,ansnum,x1,x2,y1,y2,n,i;
    long long a,b,ans;
    scanf(" %d %d %d",&n,&xx,&yy);
    for(i=0;i<xx;i++){
        scanf(" %lld",&a);
        x[i].num=i+1;
        x[i].val=a;
    }
    for(i=0;i<yy;i++){
        scanf(" %lld",&a);
        y[i].num=i+xx+1;
        y[i].val=a;
    }
    sort(x,x+xx);
    sort(y,y+yy);
    for(i=0;i<xx;i++){
        xnum[i]=x[i].num;
        xval[i]=x[i].val;
    }
    for(i=0;i<yy;i++){
        ynum[i]=y[i].num;
        yval[i]=y[i].val;
    }
    for(i=1;i<=n;i++){
        ans=1<<30;
        scanf(" %lld %lld",&a,&b);
        x1=upper_bound(xval,xval+xx,a)-xval;
        x2=lower_bound(xval,xval+xx,a)-xval;
        if(xval[x2]==a){
            ans=b*b;
            ansnum=xnum[x2];
        }else{
            if(x1==xx){
                ans=(a-xval[x1-1])*(a-xval[x1-1])+b*b;
                ansnum=xnum[x1-1];
            }else if(x1==0){
                ans=(a-xval[0])*(a-xval[0])+b*b;
                ansnum=xnum[0];
            }else{
                x2--;
                if((xval[x2]-a)*(xval[x2]-a)<(xval[x1]-a)*(xval[x1]-a)){
                    ans=(a-xval[x2])*(a-xval[x2])+b*b;
                    ansnum=xnum[x2];
                }else if((xval[x2]-a)*(xval[x2]-a)>(xval[x1]-a)*(xval[x1]-a)){
                    ans=(a-xval[x1])*(a-xval[x1])+b*b;
                    ansnum=xnum[x1];
                }else if(xnum[x2]<xnum[x1]){
                    ans=(a-xval[x2])*(a-xval[x2])+b*b;
                    ansnum=xnum[x2];
                }else{
                    ans=(a-xval[x1])*(a-xval[x1])+b*b;
                    ansnum=xnum[x1];
                }
            }
        }
        y1=upper_bound(yval,yval+yy,b)-yval;
        y2=lower_bound(yval,yval+yy,b)-yval;
        if(yval[y2]==b){
            if(ans>a*a){
                ans=a*a;
                ansnum=ynum[y2];
            }
        }else{
            if(y1==yy){
                if(ans>(yval[y1-1]-b)*(yval[y1-1]-b)+a*a){
                    ans=(yval[y1-1]-b)*(yval[y1-1]-b)+a*a;
                    ansnum=ynum[y1-1];
                }
            }else if(y1==0){
                if(ans>(yval[0]-b)*(yval[0]-b)+a*a){
                    ans=(yval[0]-b)*(yval[0]-b)+a*a;
                    ansnum=ynum[0];
                }
            }else{
                y2--;
                if((yval[y2]-b)*(yval[y2]-b)<(yval[y1]-b)*(yval[y1]-b)){
                    if(ans>(yval[y2]-b)*(yval[y2]-b)+a*a){
                        ans=(yval[y2]-b)*(yval[y2]-b)+a*a;
                        ansnum=ynum[y2];
                    }
                }else if((yval[y2]-b)*(yval[y2]-b)>(yval[y1]-b)*(yval[y1]-b)){
                    if(ans>(yval[y1]-b)*(yval[y1]-b)+a*a){
                        ans=(yval[y1]-b)*(yval[y1]-b)+a*a;
                        ansnum=ynum[y1];
                    }
                }else if(ynum[y1]<ynum[y2]){
                    if(ans>(yval[y1]-b)*(yval[y1]-b)+a*a){
                        ans=(yval[y1]-b)*(yval[y1]-b)+a*a;
                        ansnum=ynum[y1];
                    }
                }else{
                    if(ans>(yval[y2]-b)*(yval[y2]-b)+a*a){
                        ans=(yval[y2]-b)*(yval[y2]-b)+a*a;
                        ansnum=ynum[y2];
                    }
                }
            }
        }
        printf("%d",ansnum);
    }
    return 0;
}
