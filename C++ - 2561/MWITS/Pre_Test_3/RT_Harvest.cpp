/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,id;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos<o.pos;
        else            return id<o.id;
    }
};
set<A > sett;
set<A > ::iterator it,it2;
char opr[10];
int main(){
    int q,w,h,n,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&w,&h,&n);
        while(n--){
            scanf(" %s %d %d",opr,&a,&b);
            if(opr[0] == 'p'){
                it = sett.lower_bound({a-1,1});
                if(it == sett.end()){
                    if(it == sett.begin()){
                        printf("%d %d\n",a*h,(w-b-1)*h);
                    }else{
                        it--;
                        printf("%d %d\n",(a-(*it).pos-1)*h,(w-b-1)*h);
                    }
                    sett.insert({a,0});
                    sett.insert({b,1});
                    // cout << "1" << endl;
                    continue;
                }
                it2 = it;
                if((*it).pos == a-1){
                    it2--;
                    sett.erase(it);
                    // cout << "2" << endl;
                }else{
                    sett.insert({a,0});
                    it2 = sett.lower_bound({a,0});
                    // cout << "3" << endl;
                }
                if(it2 == sett.begin()){
                    printf("%d ",(*it2).pos*h);
                }else{
                    it = it2;
                    it2--;
                    printf("%d ",((*it).pos-(*it2).pos-1)*h);
                }
                it = sett.lower_bound({b+1,0});
                if(it == sett.end()){
                    sett.insert({b,1});
                    // cout << "4" << endl;
                    continue;
                }
                it2 = it;
                if((*it).pos == b+1){
                    it2++;
                    it2++;
                    sett.erase(it);
                    // cout << "5" << endl;
                }else{
                    sett.insert({b,1});
                    it2 = sett.lower_bound({b,1});
                    it2++;
                    // cout << "6" << endl;
                }
                it = it2;
                it--;
                if(it2 == sett.end()){
                    printf("%d\n",(w-(*it).pos-1)*h);
                }else{
                    printf("%d\n",((*it2).pos-(*it).pos)*h);
                }
            }else{
                it = sett.lower_bound({a,0});
                if((*it).pos == a){
                    printf("0 ");
                    sett.erase(it);
                }else{
                    it--;
                    printf("%d ",(a-(*it).pos)*h);
                    sett.insert({a-1,1});
                }
                it = sett.lower_bound({b,1});
                if((*it).pos == b){
                    printf("0\n");
                    sett.erase(it);
                }else{
                    printf("%d\n",((*it).pos-b)*h);
                    sett.insert({b+1,0});
                }
            }
            // for(auto x:sett){
            //     printf("In set : %d %d\n",x.pos,x.id);
            // }
        }
        printf("--\n");
        sett.clear();
    }
	return 0;
}
