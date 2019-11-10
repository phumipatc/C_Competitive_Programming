/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[50100],lv[50100];
int find_root(int i)
{
    if(p[i]==i) return i;
    int temp=p[i];
    p[i]=find_root(p[i]);
    lv[i]+=lv[temp];
    return p[i];
}
int main()
{
    int q,i,opr,x,y,n,m,rootx,rooty;
    scanf("%d",&q);
    while(q--){
        memset(lv,0,sizeof lv);
        int ans=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)   p[i]=i;
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&opr,&x,&y);
            if(x>n || y>n){
                ans++;
                continue;
            }
            rootx=find_root(x),rooty=find_root(y);
            if(opr==1){
                if(rootx==rooty && (((lv[x]-(lv[y]%3))+3)%3)!=0)
                    ans++;
                else{
                    p[rootx]=rooty;
                    int temp=(lv[x]-lv[y])%3;
                    if(temp<0)  lv[rootx]=-temp;
                    else        lv[rootx]=3-temp;
                }
            }else{
                if(rootx==rooty && (((lv[x]-lv[y]%3)+3)%3)!=1)
                    ans++;
                else{
                    p[rootx]=rooty;
                    int temp=(lv[x]-lv[y]-1)%3;
                    if(temp<0)  lv[rootx]=-temp;
                    else        lv[rootx]=3-temp;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/


