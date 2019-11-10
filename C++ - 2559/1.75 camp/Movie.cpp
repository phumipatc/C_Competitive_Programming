/*
TASK: Movie
LANG: C++
AUTHOR: PeaTT~
*/
#include<cstdio>
#include<algorithm>
using namespace std;
struct B{
    int s,e;
    bool operator < (const B &o) const{
        if(s < o.s)     return true;
        else            return false;
    }
};
typedef struct B B;
B b[6000];
int main(){
    int n,i,ans1=0,ans2=0,st,en;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&b[i].s,&b[i].e);
    sort(b,b+n);
    st = b[0].s, en= b[0].e;
    for(i=1;i<n;i++){
        if(en >= b[i].s)
            en = max(en, b[i].e);
        else{
            ans1 = max(ans1, en-st);
            ans2 = max(ans2, b[i].s-en);
            st = b[i].s, en= b[i].e;
        }
    }
    ans1 = max(ans1, en-st);
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}
/*
5
2 3
1 5
1 2
2 4
3 5
*/
