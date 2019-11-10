/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,i,num;
    bool operator < (const A&o)const{
        if(x!=o.x)					return x<o.x;
        else if(i!=o.i)				return i>o.i;
        else if(i==o.i && x==o.x)	return y>o.y;
    }
};
A a[700000];
stack< A > st;
int main(){
    int n,i,x,r,ans = 1,now,ch1,ch2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x,&r);
        a[i].x = x-r;
        a[i].y = x+r;
        a[i].i = 1;
        a[i].num = i+1;
        a[i+n].x = x+r;
        a[i+n].y = x-r;
        a[i+n].i = 2;
        a[i+n].num = i+1;
    }
    sort(a,a+2*n);
    for(i=0;i<n+n;i++){
        now = a[i].x;
        ch1 = 1,ch2 = 0;
        while(!st.empty()&&st.top().num!=a[i].num&&a[i].i==2){
            ch2 = 1;
            if(ch1 == 1){
                if(st.top().x == now){
                    st.pop();
                    now = st.top().x;
                    st.pop();
                }else{
                    st.pop();
                    st.pop();
                    ch1 = 0;
                }
            }else{
                st.pop();
                st.pop();
            }
        }
        if(!st.empty() && ch1 == 1 && now!=st.top().x)	ch1 = 0;
        st.push({a[i].x,0,0,a[i].num});
        if(a[i].i == 2){
            if(ch2 == 0)					ans++;
            else if(ch2 == 1 && ch1 == 1)	ans+=2;
            else if(ch2 == 1 && ch1 == 0)	ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

