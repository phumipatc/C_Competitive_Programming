/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
set<int> sett;
set<int> ::iterator it,it2;
int main(){
    int n,k,num;
    scanf("%d %d",&n,&k);
    while(k--){
        scanf("%d",&num);
        if(sett.empty()){
            printf("%d\n",n);
            sett.insert(num);
            continue;
        }
        it = it2 = sett.lower_bound(num);
        it--;
        if(it2 == sett.begin())     printf("%d\n",(*it2)-num);
        else if(it2 == sett.end())  printf("%d\n",num-(*it));
        else                        printf("%d\n",min(num-(*it),(*it2)-num));
        sett.insert(num);
    }
    return 0;
}
