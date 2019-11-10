/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int power,day,from;
    bool operator < (const A& o) const{
        if(power<o.power)         return true;
        else if(power>o.power)    return false;

    }
};
priority_queue< A> mana;
int main(){
    char opr,subopr,hl;
    int k,i,ch;
    A temp;
    scanf("%d",&k);
    for(i=1;i<=k;i++){
        scanf("%c",&opr);
        if(opr=='c'){
            scanf("%c",&subopr);
            if(subopr=='n'){
                scanf("%d",&temp.power);
                mana.push(temp);
            }else if(subopr=='r'){
                scanf("%d %d",&temp.power,&hl);
                temp.day=hl;
                temp.from=i;
                mana.push(temp);
            }
        }else if(opr=='u'){
            while(!mana.empty()){
                temp=mana.top();
                mana.pop();
                temp.power/=((i-from)/temp.day);
            }
        }
        switch(opr){
            case 4:
                ch=1;
                while(!mana.empty()){
                    temp=mana.top();
                    mana.pop();
                    if(temp.type==2){
                        if(temp.day>i){
                            printf("%d\n",temp.power);
                            ch=0;
                            break;
                        }else{
                            continue;
                        }
                    }
                    else if(temp.type==3){
                        printf("%d\n",temp.power);
                        ch=0;
                        break;
                    }
                    else if(temp.type==1){
                        if(temp.day>i){
                            printf("%d\n",temp.power);
                            ch=0;
                            break;
                        }else{
                            temp.power=temp.trans;
                            temp.type=3;
                            mana.push(temp);
                            continue;
                        }
                    }
                }
                break;
        }
    }
return 0;
}
