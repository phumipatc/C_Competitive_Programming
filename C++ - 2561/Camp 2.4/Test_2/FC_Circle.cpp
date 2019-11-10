/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,duo,genre,id;
    bool operator < (const  A&o) const{
        if(pos!=o.pos)          return pos<o.pos;
        else if(genre!=o.genre) return genre>o.genre;
        else                    return duo>o.duo;
    }
};
A a[600010];
stack<A > st;
int main(){
    int n,c,r,ans = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&c,&r);
        a[i] = {c-r,c+r,1,i};
        a[i+n] = {c+r,c-r,2,i};
    }
    sort(a+1,a+(2*n)+1);
    for(int i=1;i<=2*n;i++){
        int now = a[i].pos,cut = 1,in = 0;
        while(a[i].genre == 2 && !st.empty() && st.top().id!=a[i].id){
            in = 1;
            if(cut){
                if(st.top().pos == now){
                    st.pop();
                    now = st.top().pos;
                    st.pop();
                }else{
                    cut = 0;
                    st.pop();
                    st.pop();
                }
            }else{
                st.pop();
                st.pop();
            }
        }
        if(!st.empty() && now!=st.top().pos)    cut = 0;
        st.push({a[i].pos,0,0,a[i].id});
		if(a[i].genre == 1)	continue;
		if(cut && in)	ans+=2;
		else			ans++;
    }
    printf("%d\n",ans);
	return 0;
}