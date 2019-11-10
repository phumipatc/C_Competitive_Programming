#include<cstdio>
#include<queue>
using namespace std;
struct B {
    int i,j,fromi,fromj;
};
typedef struct B B;
char a[200][200];
int r,c;
queue< B > q;
int main(){
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
        scanf(" %c",&a[i][j]);
        if(a[i][j]=='S'){
            temp.i = i,temp.j=j;
            q.push(temp);
        }
        else if(a[i][j]=='E')
            ei=i,ej=j;
}
    }
}
