/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int sound,sizes;
};
stack< A> st;
int main(){
    int n,a,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&a,&b);
        while(1){
            if(st.top().sizes>=a){
                break;
            }else{
                printf("%d\n",st.top().sizes);
                st.pop();
            }
        }
        A temp;
        temp.sizes=a;
        temp.sound=b;
        st.push(temp);
    }
    return 0;
}
