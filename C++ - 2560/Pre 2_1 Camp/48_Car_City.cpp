/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,d,type;
    bool operator < (const A& o) const{
        if(type==1){ // down
            if(x!=o.x) return x>o.x;
            else return y>o.y;
        }else if(type==2){ // right
            if(y!=o.y) return y>o.y;
            else return x<o.x;
        }else if(type==3){ // left
            if(y!=o.y) return y>o.y;
            else return x>o.x;
        }else{ // up
            if(x!=o.x) return x>o.x;
            else return y<o.y;
        }
    }
};
A car[50500],car2[50500],car3[50500],car4[50500];
int main(){
    int q,n,i,now,ans,xx,yy,dd;
    scanf(" %d",&q);
    while(q--){
        scanf(" %d",&n);
        for(i=0;i<n;i++){
            scanf(" %d %d %d",&car[i].x,&car[i].y,&car[i].d);
            car2[i]=car3[i]=car4[i]=car[i];
            car[i].type=1;
            car2[i].type=2;
            car3[i].type=3;
            car4[i].type=4;
        }
        sort(car,car+n);
        sort(car2,car2+n);
        sort(car3,car3+n);
        sort(car4,car4+n);
        ans=0;
        //down
        now=0;
        for(i=0;i<n;i++){
            if(i==0){
                xx=car[i].x;
                dd=car[i].y-car[i].d;
                now=1;
                if(now>ans) ans=now;
            }else{
                if(xx!=car[i].x){
                    xx=car[i].x;
                    dd=car[i].y-car[i].d;
                    now=1;
                }else{
                    if(dd<=car[i].y){
                        if(dd>car[i].y-car[i].d) dd=car[i].y-car[i].d;
                        now++;
                        if(now>ans) ans=now;
                    }else{
                        now=1;
                        dd=car[i].y-car[i].d;
                    }
                }
            }
        }
        //up
        now=0;
        for(i=0;i<n;i++){
            if(i==0){
                xx=car4[i].x;
                dd=car4[i].y+car4[i].d;
                now=1;
                if(now>ans) ans=now;
            }else{
                if(xx!=car4[i].x){
                    xx=car4[i].x;
                    dd=car4[i].y+car4[i].d;
                    now=1;
                }else{
                    if(dd>=car4[i].y){
                        if(dd<car4[i].y+car4[i].d) dd=car4[i].y+car4[i].d;
                        now++;
                        if(now>ans) ans=now;
                    }else{
                        now=1;
                        dd=car4[i].y+car4[i].d;
                    }
                }
            }
        }
        //left
        now=0;
        for(i=0;i<n;i++){
            if(i==0){
                yy=car3[i].y;
                dd=car3[i].x-car3[i].d;
                now=1;
                if(now>ans) ans=now;
            }else{
                if(yy!=car3[i].y){
                    yy=car3[i].y;
                    dd=car3[i].x-car3[i].d;
                    now=1;
                }else{
                    if(dd<=car3[i].x){
                        if(dd>car3[i].x-car3[i].d) dd=car3[i].x-car3[i].d;
                        now++;
                        if(now>ans) ans=now;
                    }else{
                        now=1;
                        dd=car3[i].x-car3[i].d;
                    }
                }
            }
        }
        //right
        now=0;
        for(i=0;i<n;i++){
            if(i==0){
                yy=car2[i].y;
                dd=car2[i].x+car2[i].d;
                now=1;
                if(now>ans) ans=now;
            }else{
                if(yy!=car2[i].y){
                    yy=car2[i].y;
                    dd=car2[i].x+car2[i].d;
                    now=1;
                }else{
                    if(dd>=car2[i].x){
                        if(dd<car2[i].x+car2[i].d) dd=car2[i].x+car2[i].d;
                        now++;
                        if(now>ans) ans=now;
                    }else{
                        now=1;
                        dd=car2[i].x+car2[i].d;
                    }
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
