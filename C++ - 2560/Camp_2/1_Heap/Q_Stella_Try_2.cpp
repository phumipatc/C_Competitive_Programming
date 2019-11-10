/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long mana,half,start,type;
    bool operator < (const A&o) const{
        if(mana!=o.mana)    return mana<o.mana;
        else                return start>o.start;
    }
};
priority_queue< A> heap;
int main()
{
    char opr,opr2;
    long long k,i,ans=0,j,countt=0,ans2;
    A temp;
    scanf("%lld",&k);
    for(i=1;i<=k;i++){
        scanf(" %c",&opr);
        if(opr=='c'){
            scanf(" %c",&opr2);
            if(opr2=='n'){
                scanf("%lld",&temp.mana);
                temp.type=1;
                temp.start = i;
                heap.push(temp);
            }else{
                scanf("%lld %lld",&temp.mana,&temp.half);
                temp.start=i;
                temp.type=2;
                heap.push(temp);
            }
        }else if(opr=='u'){
            while(1){
                if(heap.empty())    break;
                temp=heap.top();
                heap.pop();
                if(temp.type==1){
                    ans+=temp.mana;
                    break;
                }else if(temp.type==2){
                    countt=(i-temp.start)/temp.half;
                    if(countt==0){
                        ans+=temp.mana;
                        break;
                    }
                    for(j=0;j<countt;j++){
                        temp.mana/=2;
                    }
                    if(temp.mana>0){
                        temp.start+=temp.half*countt;
                        heap.push(temp);
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    ans2=0;
    while(!heap.empty()){
        temp=heap.top();
        heap.pop();
        if(temp.type==1){
            ans2++;
        }else{
            countt=(k-temp.start)/temp.half;
            for(j=0;j<countt;j++){
                temp.mana/=2;
            }
            if(temp.mana!=0) ans2++;
        }
    }
    printf("%lld\n",ans2);
    return 0;
}
