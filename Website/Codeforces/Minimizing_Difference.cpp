/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<long long ,long long > countt;
set<long long > sett;
set<long long > ::iterator it,it2,nextt;
int main(){
    long long n,k,num;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&num),sett.insert(num),countt[num]++;
    it = sett.begin();    
    it2 = sett.end();
    it2--;
    while(k && sett.size()!=1){
        // printf("%lld %lld %lld\n",*it,*it2,k);
        if(countt[*it]<countt[*it2]){
            nextt = it;
            nextt++;
            long long temp = k/countt[*it];
            if(temp == 0)   break;
            if(*it+temp>=*nextt){
                countt[*nextt]+=countt[*it];
                k-=countt[*it]*(*nextt-*it);
                countt[*it] = 0;
                sett.erase(it);
                it = sett.begin();
            }else{
                countt[*it+temp]+=countt[*it];
                k-=countt[*it]*temp;
                countt[*it] = 0;
                sett.erase(it);
                sett.insert(*it+temp);
                it = sett.begin();
            }
        }else{
            nextt = it2;
            nextt--;
            long long temp = k/countt[*it2];
            if(temp == 0)   break;
            if(*it2-temp<=*nextt){
                countt[*nextt]+=countt[*it2];
                k-=countt[*it2]*(*it2-*nextt);
                countt[*it2] = 0;
                sett.erase(it2);
                it2 = sett.end();
                it2--;
            }else{
                countt[*it2-temp]+=countt[*it2];
                k-=countt[*it2]*temp;
                countt[*it2] = 0;
                sett.erase(it2);
                sett.insert(*it2-temp);
                it2 = sett.end();
                it2--;
            }
        }
    }
    it = sett.begin();
    it2 = sett.end();
    it2--;
    printf("%lld\n",*it2-*it);
    return 0;
}