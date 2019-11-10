/*
TASK: Jump Jom Jun
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <cstdlib>
#define q_empty ((be==end)?true:false)
#define enqueue(a) (queue[end++]=a)
#define dequeue() (queue[be++])
#define MIN(a,b) ((a<b)?a:b)
#define INF 2000005000
using namespace std;
int queue[20000]={0},be=0,end=0;
int map[105][10005];

int main(){
    int n,m,x,i,j;
    char data[10005];
    scanf("%d %d\n",&n,&m);
    for(i=0;i<n;i++){
        gets(data);
        be=end=0;
        for(j=0;j<m;j++) map[i][j]=-1;
        for(j=0;j<m;j++) if(data[j]=='1') {map[i][j]=0;enqueue(j);}
        while(!q_empty){
            x=dequeue();
            int le=(x==0)?m-1:x-1,ri=(x+1)%m;
            if(map[i][le]==-1) {map[i][le]=map[i][x]+1;enqueue(le);}
            if(map[i][ri]==-1) {map[i][ri]=map[i][x]+1;enqueue(ri);}
        }
    }
    int min=INF;
    for(j=0;j<m;j++){
        int sum=0;
        for(i=0;i<n;i++){
            sum+=map[i][j];
            if(map[i][j]==-1) {printf("-1\n");exit(0);}
        }
        min=MIN(min,sum);
    }
    printf("%d\n",min);
    return 0;
}
