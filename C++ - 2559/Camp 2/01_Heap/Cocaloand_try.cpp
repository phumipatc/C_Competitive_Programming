/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int point,death,newpoint,type;
    bool operator < (const A&o) const{
        if(point>o.point)       return true;
        else if(point<o.point)  return false;
        else if(type>o.type)    return true;
        else if(type<o.type)    return false;
    }
};
priority_queue< A> h;
int main(){
    int p,opr,i,ch;
    A temp;
    scanf("%d",&p);
    for(i=1;i<=p;i++){
        scanf("%d",&opr);
        if(opr==1){
            scanf("%d %d",&temp.point,&temp.death);
            temp.type=2;
            h.push(temp);
        }else if(opr==2){
            scanf("%d",&temp.point);
            temp.type=3;
            h.push(temp);
        }else if(opr==3){
            scanf("%d %d %d",&temp.point,&temp.death,&temp.newpoint);
            temp.type=1;
            h.push(temp);
        }else{
            ch=1;
            while(!h.empty()){
                temp=h.top();
                h.pop();
                if(temp.type==2){
                    if(i<temp.death){
                        printf("%d\n",temp.point);
                        ch=0;
                        break;
                    }else{
                        continue;
                    }
                }else if(temp.type==1){
                    if(i<temp.death){
                        printf("%d\n",temp.point);
                        ch=0;
                        break;
                    }else{
                        temp.point=temp.newpoint;
                        temp.type=3;
                        h.push(temp);
                        continue;
                    }
                }else if(temp.type==3){
                    printf("%d\n",temp.point);
                    ch=0;
                    break;
                }
            }
            if(ch)
                printf("GREAN\n");
        }
    }
return 0;
}
/*
11
2 5
4
4
1 10 5
2 15
4
3 20 8 40
2 30
2 45
4
4
*/
