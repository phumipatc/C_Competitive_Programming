/*
    TASK : Q_game1
    AUTHOR : Tanapoon Laoaroon
    SCHOOL : RYW
    LANG : CPP
*/
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct A{
    int x,y;
};
queue<pair<int,int> > a,b;
pair<int,int> bon;
int peat[1000][1000],marka[550][550],markb[550][550];
int main()
{
    int r,c,i,j,dir[]={0,-1},dic[]={1,0},A,B,x_new,y_new,ch=1;
    long long sum=0;
    scanf(" %d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %d",&peat[i][j]);
        }
    }
    a.push(make_pair(0,r-1));
    b.push(make_pair(0,r-1));
    while(!a.empty() && !b.empty()){
        A=a.size();
        B=b.size();
        sum+=A*B;
        for(i=0;i<A;i++){
            for(j=0;j<2;j++){
                x_new=a.front().first+dic[j];
                y_new=a.front().second+dir[j];
                if(x_new<0||x_new>=c||y_new<0||y_new>=r) continue;
                if(peat[y_new][x_new] || marka[y_new][x_new]) continue;
                marka[y_new][x_new]=1;
                a.push(make_pair(x_new,y_new));
            }
            a.pop();
        }
        for(i=0;i<B;i++){
            for(j=0;j<2;j++){
                x_new=b.front().first+dic[j];
                y_new=b.front().second+dir[j];
                if(x_new<0||x_new>=c||y_new<0||y_new>=r) continue;
                if(peat[y_new][x_new]  || markb[y_new][x_new]) continue;
                markb[y_new][x_new]=1;
                b.push(make_pair(x_new,y_new));
            }
            b.pop();
        }
//        printf("%d %d\n",(int)a.size(),(int)b.size());
    }
    printf("%lld",sum);
    return 0;
}
