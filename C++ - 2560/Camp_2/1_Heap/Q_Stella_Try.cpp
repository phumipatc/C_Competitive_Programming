/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int mana,half,time,typee,last;
    bool operator < (const A&o) const{
        if(mana < o.mana)
            return true;
        else if(mana > o.mana)
            return false;
        else if(time > o.time)
            return true;
        else
            return false;
    }
};
priority_queue< A> heap;
int main(){
    A temp;
    int k,i,ans=0,countt=0,num,hl;
    char opr,type;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf(" %c",&opr);
        if(opr=='c'){
            scanf(" %c",&type);
            if(type=='n'){
                scanf("%d",&num);
                temp.mana=num;
                temp.half=100100;
                temp.time=temp.last=i;
                temp.typee=1;
                heap.push(temp);
            }else{
                scanf("%d %d",&num,&hl);
                temp.mana=num;
                temp.half=hl;
                temp.time=temp.last=i;
                temp.typee=2;
                heap.push(temp);
            }
        }else{
            while(!heap.empty()){
                temp=heap.top();
                heap.pop();
                if(temp.typee==2){
                    temp.mana/=pow(2,(i-temp.last)/temp.half);
                    if(temp.last==i){
                        ans+=temp.mana;
                        //printf("%d\n",ans);
                        break;
                    }else{
                        temp.last=i;
                        heap.push(temp);
                    }
                }else{
                    ans+=temp.mana;
                    //printf("%d\n",ans);
                    break;
                }
            }
        }
    }
    while(!heap.empty()){
        countt++;
        heap.pop();
    }
    printf("%d\n%d",ans,countt);
	return 0;
}
