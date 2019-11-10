/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int h,num;
};
stack<A > st;
int a[100010];
int main(){
    int l,q,temp,idx,p;
    scanf("%d %d",&l,&q);
    for(int i=1;i<=l;i++){
        scanf("%d",&temp);
        while(!st.empty() && st.top().h>=temp)    st.pop();
        if(st.empty())  p = 0;
        else            p = max(temp-st.top().h,st.top().num);
        st.push({temp,p});
        a[i] = p;
    }
    sort(a+1,a+l+1);
    while(q--){
        scanf("%d",&temp);
        idx = upper_bound(a+1,a+l+1,temp)-a;
        printf("%d\n",l-idx+1);
    }
	return 0;
}
