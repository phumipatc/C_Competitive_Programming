/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long day,pluss,i,j,k,now,pass,sum=0;
struct A{
    int sp;
    bool operator<(const A& o) const
    {
        if(sp>o.sp)
            return false;
        else if(sp<o.sp)
            return true;
    }
};
priority_queue< A> skill;
int main(){
    A temp;
    scanf("%lld %lld",&day,&pluss);
    for(i=0;i<day;i++){
        scanf("%lld %lld",&now,&pass);
        for(j=0;j<now;j++){
            scanf("%lld",&temp.sp);
            temp.sp-=(pluss*i);
            skill.push(temp);
        }
        for(k=0;k<pass;k++){
            temp=skill.top();
            skill.pop();
            sum+=(temp.sp+(pluss*i));
        }
    }
    printf("%lld",sum);
return 0;
}
