/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long st,en;
    bool operator <(const A & o)const{
        if(en!=o.en)    return en<o.en;
        else            return st>o.st;
    }
};
A a[100100];
stack < A> s;
int main()
{
    long long n,m,sizee,i;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].st,&a[i].en);
    sort(a,a+n);
    for(i=0;i<n;i++){
        while(!s.empty()){
            A temp=s.top();
            s.pop();
            if(!s.empty() && s.top().en >= a[i].st)   continue;
            else{
                if(a[i].st <= temp.st) continue;
                else if(!s.empty() && a[i].st == s.top().en+1)    continue;
                else{
                    s.push(temp);
                    break;
                }
            }
        }
        s.push({a[i].st,a[i].en});
    }
    sizee = s.size();
    printf("%lld\n",sizee);
    return 0;
}
/*
4 10
1 5
3 7
4 8
8 10

4 10
1 10
1 4
5 6
7 10
*/
