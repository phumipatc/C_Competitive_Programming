/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int beauty,day,trans,type;
    bool operator < (const A& o) const{
        if(beauty>o.beauty)         return true;
        else if(beauty<o.beauty)    return false;
        else if(type>o.type)        return true;
        else                        return false;
    }
};
priority_queue< A> veget;
int main(){
    int p,i,opr,ch;
    A temp;
    scanf("%d",&p);
    for(i=0;i<p;i++){
        scanf("%d",&opr);
        switch(opr){
            case 1:
                scanf("%d %d",&temp.beauty,&temp.day);
                temp.type=2;
                veget.push(temp);
                break;
            case 2:
                scanf("%d",&temp.beauty);
                temp.type=3;
                veget.push(temp);
                break;
            case 3:
                scanf("%d %d %d",&temp.beauty,&temp.day,&temp.trans);
                temp.type=1;
                veget.push(temp);
                break;
            case 4:
                ch=1;
                while(!veget.empty()){
                    temp=veget.top();
                    veget.pop();
                    if(temp.type==2){
                        if(temp.day>i){
                            printf("%d\n",temp.beauty);
                            ch=0;
                            break;
                        }else{
                            continue;
                        }
                    }
                    else if(temp.type==3){
                        printf("%d\n",temp.beauty);
                        ch=0;
                        break;
                    }
                    else if(temp.type==1){
                        if(temp.day>i){
                            printf("%d\n",temp.beauty);
                            ch=0;
                            break;
                        }else{
                            temp.beauty=temp.trans;
                            temp.type=3;
                            veget.push(temp);
                            continue;
                        }
                    }
                }
                if(ch)
                    printf("GREAN\n");
                break;
        }
    }
return 0;
}
