/*
    TASK: E
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C++
            */
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int > h;
int main()
{
    int q,d;
    char k;
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&k);
        if(k=='A'){
            scanf("%d",&d);
            h.push(d*-1);
        }else{
            if(h.empty()){
                printf("-1\n");
                continue;
            }
            printf("%d\n",h.top()*-1);
            h.pop();
            }
    }
       return 0;
}
/*
9
A 7
A 3
A 5
A 3
B
A 4
B
B
B
*/
