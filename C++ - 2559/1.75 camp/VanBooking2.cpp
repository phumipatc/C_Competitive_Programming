/*
TASK: Van Booking2
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <queue>
using namespace std;
struct A{
    int day,no;
    bool operator < (const A& o) const{
        if(day > o.day)         return true;
        else if(day < o.day)    return false;
        else if(no > o.no)      return true;
        return false;
    }
};
typedef struct A A;
priority_queue< A > a;
int main(){
    int n,k,i,t;
    A temp;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++){
        temp.day=0,temp.no=i;
        a.push(temp);
    }
    while(n--){
        scanf("%d",&t);
        printf("%d\n",a.top().no);
        temp.day = t + a.top().day;
        temp.no = a.top().no;
        a.pop();
        a.push(temp);
    }
    return 0;
}
