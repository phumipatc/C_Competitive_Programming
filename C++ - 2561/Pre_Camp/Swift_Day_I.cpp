/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long st,en;
    bool operator <(const A & o)const{
        if(en!=o.en)    return en<o.en;
        else            return st>o.st;
    }
};
A a[100100];
stack < A> st;
int main(){
    long long n,m,sizee,i;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].st,&a[i].en);
    sort(a,a+n);
    for(i=0;i<n;i++){
        while(!st.empty()){
            A now = st.top();
            st.pop();
            if(!st.empty() && st.top().en >= a[i].st)   continue;
            else{
                if(a[i].st <= now.st) continue;
                else if(!st.empty() && a[i].st == st.top().en+1)    continue;
                else{
                    st.push(now);
                    break;
                }
            }
        }
        st.push({a[i].st,a[i].en});
    }
    sizee = st.size();
    printf("%lld\n",sizee);
    return 0;
}
/*
4 10
1 5
3 7
4 8
8 10

4 10
1 10
1 4
5 6
7 10
*/
