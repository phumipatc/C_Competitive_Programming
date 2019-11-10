#include<cstdio>
#include<queue>
using namespace std;
struct B{
    int a,b,c;
    bool operator < (const B&o)const{
        if(a>o.a)
            return true;
        else if(a<o.a)
            return false;
        else if(b<o.b)
            return true;
        else if(b>o.b)
            return false;
        else if(c>o.c)
            return true;
        else if(c<o.c)
            return false;
    }
};
typedef struct B B;
priority_queue<B > heap;
int main(){
    int n,i;
    B temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&temp.a,&temp.b,&temp.c);
        heap.push(temp);
    }
    for(i=0;i<n;i++){
        temp=heap.top();
        printf("%d %d %d\n",temp.a,temp.b,temp.c);
        heap.pop();
    }
    return 0;
}
