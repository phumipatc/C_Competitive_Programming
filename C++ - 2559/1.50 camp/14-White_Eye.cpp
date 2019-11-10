/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack<int > s;
int main(){
    int n,m,i,num;
    char a;
    scanf("%d %d",&n,&m);
    for(i=0;i<n+m;i++){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&num);
            while(!s.empty()){
                if(s.top()<=num)
                    s.pop();
                else
                    break;
            }
            s.push(num);
        }else if(a=='B')
            printf("%d\n",s.size());
    }
return 0;
}
