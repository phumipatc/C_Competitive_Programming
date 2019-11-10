/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<queue>
using namespace std;
struct A{
    int id,rank,time;
    bool operator < (const A & o) const{
        if(rank<o.rank){
            return true;
        }else if(rank>o.rank){
            return false;
        }else if(time>o.time){
            return true;
        }else{
            return false;
        }
    }
};
priority_queue<A > h;
int main()
{
    A temp;
    int n,r,i,m;
    scanf("%d %d",&n,&r);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        if(m==1){
            scanf("%d %d",&temp.id,&temp.rank);
            temp.time=i;
            h.push(temp);
        }else if(m==2){
            if(h.empty())
                printf("-1\n");
            else{
                printf("%d\n",h.top().id);
                h.pop();
            }
        }
    }
return 0;
}
