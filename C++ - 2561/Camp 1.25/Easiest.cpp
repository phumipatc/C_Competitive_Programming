/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int > heap;
int main(){
    int n,num;
    char opr;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&opr);
        if(opr == 'A'){
            scanf("%d",&num);
            heap.push(-num);
        }else{
            if(heap.empty())
                printf("-1\n");
            else{
                printf("%d\n",-heap.top());
                heap.pop();
            }
        }
    }
	return 0;
}
