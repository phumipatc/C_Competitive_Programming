#include<cstdio>
#include<algorithm>
using namespace std;
struct B
{
    int s,e;
    bool operator < (const B &o) const{
    if(e==o.e){
            return s<o.s;
        }
        return e < o.e;
    }
};
typedef struct B B;
B b[100100];
int main(){
    int n,i,st,en,maxx=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&b[i].s,&b[i].e);
     sort(b,b+n);
     en = b[0].e;
     for(i=1;i<n;i++){
        if(en <= b[i].s){
            maxx++;
            en = b[i].e;
        }
     }
    printf("%d\n",maxx);
    return 0;
}
