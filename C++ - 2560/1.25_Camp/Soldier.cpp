/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int ID,Rank,time;
    bool operator < (const A & o) const{
        if(Rank<o.Rank)               return true;
        else if(Rank>o.Rank)        return false;
        else if(time>o.time)          return true;
        else                                return false;
    }
};
priority_queue< A> heap;
int main(){
    A temp;
    int n,r,cmd,i;
    scanf("%d %d",&n,&r);
    for(i=0;i<n;i++){
        scanf("%d",&cmd);
        if(cmd==1){
            scanf("%d %d",&temp.ID,&temp.Rank);
            temp.time=i;
            heap.push(temp);
        }else if(cmd==2){
            if(heap.empty())    printf("-1\n");
            else{
                printf("%d\n",heap.top().ID);
                heap.pop();
            }
        }
    }
return 0;
}
