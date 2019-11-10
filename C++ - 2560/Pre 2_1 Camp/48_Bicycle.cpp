/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator <(const A & o) const{
        return w>o.w;
    }
};
A a[70100];
map<int,int> ma;
int P[50100];
int root(int x){
    if(P[x]==x)
        return x;
    return P[x]=root(P[x]);
}
int main(){
    int q,i,num,st,en,m,n,ra,rb;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&m,&n);
        for(i=1;i<=m;i++){
            scanf("%d",&num);
            ma[num]=i;
            P[i]=i;
        }
        for(i=0;i<n;i++){
            scanf("%d %d %d",&st,&en,&a[i].w);
            a[i].u=ma[st],a[i].v=ma[en];
//            printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
        }
        sort(a,a+n);
        int ans=0;
        for(i=0;i<n;i++){

            ra=root(a[i].u);
            rb=root(a[i].v);
            if(ra!=rb){
                P[rb]=ra;
            }else{
//                printf("\n%d %d\n",a[i].u,a[i].v);
                ans+=a[i].w;
            }
        }
        printf("%d\n",ans);
    }
return 0;
}
/*
2
8 10
1 2 3 4 5 6 7 8
1 2 3
1 5 5
2 3 4
2 6 3
3 4 2
3 7 5
4 8 5
5 6 2
6 7 7
7 8 3

14 18
5 11 13 0 3 8 6 2 12 14 1 9 10 4
5 0 2
5 6 7
5 10 7
11 6 5
11 10 9
11 12 4
13 14 3
13 8 5
13 12 6
0 1 7
3 2 7
3 8 1
3 4 1
8 9 1
6 1 7
2 1 9
14 9 1
9 4 3
*/
