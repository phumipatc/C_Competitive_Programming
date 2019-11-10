/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue< int> heap;
int main(){
    int n,num;
    char a;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&num);
            heap.push(num*-1);
        }else if(a=='B'){
            if(heap.empty()){
                printf("-1\n");
            }else{
                printf("%d\n",heap.top()*-1);
                heap.pop();
            }
        }
    }
return 0;
}
