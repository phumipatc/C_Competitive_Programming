/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int mp,st,half,type;
    bool operator < (const A&o) const{
        if(mp!=o.mp)
            return mp < o.mp;
        return st > o.st;
    }
};
priority_queue< A> heap;
int main(){
    A temp;
    long long k,i,ans1=0;
    char opr,opr2;
    scanf("%lld",&k);
    for(i=1;i<=k;i++){
        scanf(" %c",&opr);
        if(opr=='c'){
            scanf(" %c",&opr2);
            if(opr2=='n'){
                scanf("%lld",&temp.mp);
                temp.st=i;
                temp.type=1;
                heap.push(temp);
            }else{
                scanf("%lld %lld",&temp.mp,&temp.half);
                temp.st=i;
                temp.type=2;
                heap.push(temp);
            }
        }else if(opr=='u'){
            while(1){
                if(heap.empty())    break;
                temp=heap.top();
                heap.pop();
                if(temp.type==1){
                    ans1+=temp.mp;
                    break;
                }else if(temp.type==2){
                    long long countt=(i-temp.st)/temp.half;
                    if(countt==0){
                        ans1+=temp.mp;
                        break;
                    }
                    for(long long j=0;j<countt;j++)
                        temp.mp/=2;
                    if(temp.mp>0){
                        temp.st+=countt*temp.half;
                        heap.push(temp);
                    }
                }
            }
        }
    }
    long long ans2=0;
    while(!heap.empty()){
        temp=heap.top();
        heap.pop();
        if(temp.type==1)
            ans2++;
        else{
            long long countt=(k-temp.st)/temp.half;
            for(long long j=0;j<countt;j++)
                temp.mp/=2;
            if(temp.mp!=0)
                ans2++;
        }
    }
    printf("%lld\n%lld\n",ans1,ans2);
	return 0;
}
