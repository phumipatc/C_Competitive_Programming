/*
TASK: Enemy Pair
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
using namespace std;
struct A{
    int v,d,use;
};
typedef struct A A;
A a[30];
int n,ans;
void play(int state,int sum){
    if(state==n+1){
        if(sum>ans) ans=sum;    return ;
    }
    if(a[a[state].d].use==0){
        a[state].use=1;
        play(state+1,sum+a[state].v);
        a[state].use=0;
    }
    play(state+1,sum);
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d %d",&a[i].v,&a[i].d);
    ans=0;
    play(1,0);
    printf("%d\n",ans);
	return 0;
}
/*
3
10 0
20 1
30 1
*/
