/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int day,no;
    bool operator < (const A & o) const{
        if(day>o.day)
            return true;
        else if(day<o.day)
            return false;
        else if(no>o.no)
            return true;
        else
            return false;
    }
};
priority_queue< A> heap;
int main()
{
    int n,k,d;
    A temp;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        temp.day=0;
        temp.no=i;
        heap.push(temp);
    }
    while(n--){
        scanf("%d",&d);
        printf("%d\n",heap.top().no);
        temp.day=heap.top().day+d;
        temp.no=heap.top().no;
        heap.pop();
        heap.push(temp);
    }
	return 0;
}
