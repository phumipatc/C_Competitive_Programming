/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,v;
    bool operator < (const A & o) const{
        if(v!=o.v) return v>o.v;
    }
};
priority_queue< A > dijk;
A temp;
char a[200][200];
int dir[8]={0,0,1,-1,1,1,-1,-1},dic[8]={1,-1,0,0,1,-1,1,-1},dist[200][200];
int main()
{
    int r,c,ma=-1,q,i,j,k,eni,enj,sti,stj,nowi,nowj,nowv,nexti,nextj,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        ma=-1,ch=0;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                scanf(" %c",&a[i][j]);
                if(isdigit(a[i][j]) && a[i][j]-'0' > ma){
                        ma=a[i][j]-'0';
                        eni=i,enj=j;
                }
            }
        }
        scanf("%d %d",&sti,&stj);
        temp.i=sti,temp.j=stj,temp.v=a[sti][stj]-'0';
        dijk.push(temp);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                dist[i][j]=1<<30;
        dist[sti][stj]=0;
        while(!dijk.empty()){
            temp = dijk.top();
            dijk.pop();
            nowi=temp.i,nowj=temp.j,nowv=temp.v;
//            printf("%d %d %d\n",nowi,nowj,nowv);
            if(nowi==eni&&nowj==enj){
                printf("%d\n",dist[nowi][nowj]);
                ch=1;
                break;
            }
            for(k=0;k<8;k++){
                nexti=nowi+dir[k],nextj=nowj+dic[k];
//                printf("%d %d %d %d\n",nowi,nowj,nexti,nextj);
                if(nexti<0||nextj<0||nexti>=r||nextj>=c)  continue;
                if(a[nexti][nextj]=='#')    continue;
                if(a[nexti][nextj]==a[nowi][nowj] && dist[nowi][nowj]+1<dist[nexti][nextj]){
                    dist[nexti][nextj]=dist[nowi][nowj]+1;
                    temp.i=nexti,temp.j=nextj,temp.v=dist[nexti][nextj];
                    dijk.push(temp);
                }
                nowv = (abs((a[nexti][nextj]-'0')-(a[nowi][nowj]-'0'))+1)*(abs((a[nexti][nextj]-'0')-(a[nowi][nowj]-'0'))+1);
                if(a[nexti][nextj]!=a[nowi][nowj] && dist[nowi][nowj]+nowv<dist[nexti][nextj]){
                    dist[nexti][nextj]=dist[nowi][nowj]+nowv;
                    temp.i=nexti,temp.j=nextj,temp.v=dist[nexti][nextj];
                    dijk.push(temp);
                }
            }
        }
        if(ch==0)  printf("NO\n");
        while(!dijk.empty())
            dijk.pop();
    }
    return 0;
}
/*
2
5 5
11111
1###1
12341
12221
12221
0 0
*/
