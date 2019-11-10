/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map <long long ,long long > mapp;
int main(){

    long long n,k,q,i,now;
    scanf("%lld",&q);
    for(i=1;i<=q;i++){
        scanf("%lld %lld",&n,&k);
        mapp.insert(make_pair(n,1));
        while(1){
            map <long long,long long> :: iterator it=mapp.end();
            it--;
            k-=(*it).second;
            now=(*it).first;
            if(k<=0){
                printf("Case #%lld: %lld %lld\n",i,now/2,(now-1)/2);
                break;
            }
            mapp.erase(it);
            mapp[now/2]+=(*it).second;
            mapp[(now-1)/2]+=(*it).second;
        }
        mapp.clear();
    }
    return 0;
}
/*
2
6
1 2 3
3 4 8
3 5 4
5 6 7
2 3 4
6
1 2 3
3 4 8
3 5 4
5 6 7
2 3 4
*/
