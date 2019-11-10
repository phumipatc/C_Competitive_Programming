 /*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,po;
    bool operator < ( const A&o)const{
        if(po < o.po) return true;
        else if(po > o.po)    return false;
        else if(num < o.num)  return true;
        else                return false;
    }

};
A temp;
priority_queue< A > h;
int a[1000100],ch[1000100];
int main(){
    int n,l,r,i,p,q,c,d;
    char opr;
    scanf("%d %d %d",&n,&l,&r);
    q = l+r;
    for(i=1;i<=n;i++){
        temp.po = 0;
        temp.num = i;
        h.push(temp);
    }
    while(q--){
        scanf(" %c",&opr);
        if(opr == 'L'){
            scanf("%d %d",&c,&d);
            a[d]++;
            temp.num = d;
            temp.po = a[d];
            h.push(temp);
        }else if(opr == 'C'){
            scanf("%d %d",&c,&d);
            a[d]+=3;
            temp.num = d;
            temp.po = a[d];
            h.push(temp);
        }else if(opr == 'R'){
            while(ch[h.top().num]==1){
                h.pop();
            }
            printf("%d\n",h.top().num);
        }else if(opr=='D'){
            while(ch[h.top().num]==1){
                h.pop();
            }
            ch[h.top().num]=1;
            h.pop();
        }
    }
    return 0;
    }
