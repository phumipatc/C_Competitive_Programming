/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2050][2050],c[2050][2050];
struct B{
    int i,j,d;
};
queue< B> b;
main(){
    B temp;
    int q,n,m,i,j,si,sj,ei,ej,d,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='A'){
                    si=i;
                    sj=j;
                }
                if(a[i][j]=='B'){
                    ei=i;
                    ej=j;
                }
            }
        }
        temp.i=si;
        temp.j=sj;
        temp.d=0;
        ch=1;
        b.push(temp);
        while(!b.empty()){
            i=b.front().i;
            j=b.front().j;
            d=b.front().d;
            b.pop();
            if(i==ei && j==ej){
                printf("%d\n",d);
                ch=0;
                break;
            }
            if(i-1>=0 && (a[i-1][j]=='.' || a[i-1][j]=='B') && c[i-1][j]!=1){
                c[i-1][j]=1;
                temp.i=i-1;
                temp.j=j;
                temp.d=d+1;
                b.push(temp);
            }
            if(j-1>=0 && (a[i][j-1]=='.' || a[i][j-1]=='B') && c[i][j-1]!=1){
                c[i][j-1]=1;
                temp.i=i;
                temp.j=j-1;
                temp.d=d+1;
                b.push(temp);
            }
            if(i+1<n && (a[i+1][j]=='.' || a[i+1][j]=='B') && c[i+1][j]!=1){
                c[i+1][j]=1;
                temp.i=i+1;
                temp.j=j;
                temp.d=d+1;
                b.push(temp);
            }
            if(j+1<m && (a[i][j+1]=='.' || a[i][j+1]=='B') && c[i][j+1]!=1){
                c[i][j+1]=1;
                temp.i=i;
                temp.j=j+1;
                temp.d=d+1;
                b.push(temp);
            }
        }
        if(ch)
            printf("-1\n");
        memset(c,0,sizeof(c));
        while(!b.empty())
            b.pop();
    }
return 0;
}
