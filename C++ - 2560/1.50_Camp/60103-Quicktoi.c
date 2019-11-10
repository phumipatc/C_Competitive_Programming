/*
    TASK : Quick TOI
    AUTHOR : Tanapoon Laoaroon
    SCHOOL : RYW
    LANG : CPP
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct A{
    int now,pow;
};
vector<int> peat[1010];
queue<A> lan;
int mark[1010];
A token;
int main()
{
    int n,i,j,coun=0,a,b,c,d,re;
    scanf(" %d",&n);
    while(n--){
        scanf(" %d %d",&a,&b);
        peat[a].push_back(b);
        peat[b].push_back(a);
    }
    for(i=0;i<1010;i++){
        if(peat[i].size()!=0){coun++;
//            printf("%d(%d) : ",i,peat[i].size());
//            for(j=0;j<peat[i].size();j++){
//                printf("%d ",peat[i][j]);
//            }
//            printf("\n");
        }
    }
    re=coun;
    while(1){
        coun=re;
        scanf(" %d %d",&a,&b);
        if(a==0 && b==0) return 0;
        mark[a]=-1;
        token.now=a;
        token.pow=0;
        lan.push(token);
        while(!lan.empty()){
            if(lan.front().pow>=b){
                lan.pop();
                continue;
            }
            d=lan.front().now;
            c=peat[d].size();
            for(i=0;i<c;i++){
                if(mark[peat[d][i]]==-1) continue;
                coun--;
                mark[peat[d][i]]=-1;
                token.now=peat[d][i];
                token.pow=lan.front().pow+1;
                lan.push(token);
            }
            lan.pop();
        }
        printf("%d\n",coun-1);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
16
10 15
15 20
20 25
10 30
30 47
47 50
25 45
45 65
15 35
35 55
20 40
50 55
35 40
55 60
40 60
60 65
35 2
35 3
0 0
*/
