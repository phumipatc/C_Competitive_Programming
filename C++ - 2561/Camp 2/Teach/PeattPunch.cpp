/*
    TASK: Peatt Punch
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
stack< PII > st;
int a[100100];
int main()
{
	int l,q,i,h,power;
	scanf("%d %d",&l,&q);
	for(i=0;i<l;i++){
        scanf("%d",&h);
        while(!st.empty() && st.top().first >= h) st.pop();
        if(st.empty()) power=0;
        else    power=max(st.top().second, h-st.top().first);
        a[i]=power;
        st.push(make_pair(h,power));
	}
	sort(a,a+l);
	while(q--){
        scanf("%d",&h);
        printf("%d\n",l - (upper_bound(a,a+l,h)-a));
	}
    return 0;
}
/*
5 2 1 3 4 2 3 2 1
*/
