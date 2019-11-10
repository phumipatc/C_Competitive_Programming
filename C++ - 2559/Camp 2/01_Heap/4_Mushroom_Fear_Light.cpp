/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long position;
    bool operator<(const A& o) const{
        if(position > o.position){
            return false;
        }
        else if(position < o.position){
            return true;
        }
    }
};
priority_queue< A > mushroom;
int main(){
    long long n,l,num,distance,i,j,light;
    double multi=0,px,py,h;
    A temp;
    scanf("%lld %lld %lf",&n,&l,&h);
    for(i=0;i<n;i++){
        scanf("%lld",&num);
            for(j=0;j<num;j++){
                scanf("%lld",&distance);
                temp.position = distance;
                mushroom.push(temp);
            }
            scanf("%lf %lf",&px,&py);
            multi = h / py;
            light = l + px*multi;
            while(1){
            temp = mushroom.top();
            if(temp.position >= light){
                mushroom.pop();
            }else if(temp.position < light){
                break;
            }
        }
        printf("%d\n",mushroom.size());
    }
}
