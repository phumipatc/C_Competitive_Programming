/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long price;
    bool operator<(const A& o)const{
        if(price > o.price){
            return true;
        }else if(price < o.price){
            return false;
        }
    }
};
priority_queue < A > slot;
int main(){
    long long q,n,m,k,opr,New,i,sum,minuss,j;
    A temp;
    scanf("%lld",&q);
    for(i=0;i<q;i++){
        scanf("%lld %lld %lld",&n,&m,&k);
        for(j=0;j<n;j++){
            scanf("%lld",&temp.price);
            slot.push(temp);
        }
        minuss = 0,sum=0;
        for(j=0;j<m;j++){
        scanf("%lld",&opr);
        switch(opr){
            case 1 :scanf("%lld",&New);
                    temp.price=New-minuss;
                    slot.push(temp);
                    break;
            case 2 :minuss+= k;
                    break;
            case 3 :if(!slot.empty()){
                        temp=slot.top();
                        slot.pop();
                    }
                    break;
                }
            }
        printf("%d ",slot.size());
        while(!slot.empty()){
            temp = slot.top();
            slot.pop();
            sum = sum + temp.price + minuss;
        }
        printf("%lld\n",sum);
    }
}
