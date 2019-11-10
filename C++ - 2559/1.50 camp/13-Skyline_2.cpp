/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<stack>
using namespace std;
stack<int > st;
int main(){
    int n,w,i,ans=0,h;
    st.push(0);
    scanf("%d %d",&n,&w);
    for(i=0;i<n;i++){
        scanf("%d %d",&w,&h);
        for(;st.top()>h;st.pop(),ans++);
        if(st.top()<h)
            st.push(h);
    }
    ans+=st.size()-1;
    printf("%d",ans);
return 0;
}
/*
10 26
1 1
2 2
5 1
6 3
8 1
11 0
15 2
17 3
20 2
22 1
*/
