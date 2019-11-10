/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
struct B{
    int value,type;
};
int a[200][200],dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}},dic[3][2]={{1,0},{0,-1}};
B b[200][200];
queue< A> q;
int main()
{
    A temp;
    int r,c,i,j,k,sti,stj,eni,enj,nexti,nextj,ans1=0,ans2,ch=0;
    scanf("%d %d %d %d %d %d",&r,&c,&sti,&stj,&eni,&enj);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            b[i][j].value=0,b[i][j].type=0;
        }
    }
    q.push({sti,stj});
    b[sti][stj].value=1,b[sti][stj].type=1;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(k=0;k<4;k++){
            nexti=temp.i+dir[k][0],nextj=temp.j+dir[k][1];
            if(b[nexti][nextj].value==0 && a[nexti][nextj]==1){
                b[nexti][nextj].value=b[temp.i][temp.j].value+1;
                b[nexti][nextj].type=1;
                q.push({nexti,nextj});
            }
        }
    }
    q.push({eni,enj});
    b[eni][enj].value=1,b[eni][enj].type=2;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        for(k=0;k<4;k++){
            nexti=temp.i+dir[k][0],nextj=temp.j+dir[k][1];
            if(b[nexti][nextj].value==0 && a[nexti][nextj]==1){
                b[nexti][nextj].value=b[temp.i][temp.j].value+1;
                b[nexti][nextj].type=2;
                q.push({nexti,nextj});
            }
        }
    }
    ans2=1e9;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(b[i][j].type==0){
//                printf("\n%d %d\n",i,j);
                for(ch=0,k=0;k<3;k++){
                    nexti=i+dic[k][0],nextj=j+dic[k][1];
                    if(nexti>=1 && nexti<=r && nextj>=1 && nextj<=c){
                        if(b[nexti][nextj].type!=0 && b[i+1][j].type!=0 && b[i+1][j].type!=b[nexti][nextj].type){
                            ch=1;
                            ans2=min(ans2,b[i+1][j].value+b[nexti][nextj].value+1);
                        }
                        if(b[nexti][nextj].type!=0 && b[i-1][j].type!=0 && b[i-1][j].type!=b[nexti][nextj].type){
                            ch=1;
                            ans2=min(ans2,b[i-1][j].value+b[nexti][nextj].value+1);
                        }
                        if(b[nexti][nextj].type!=0 && b[i][j+1].type!=0 && b[i][j+1].type!=b[nexti][nextj].type){
                            ch=1;
                            ans2=min(ans2,b[i][j+1].value+b[nexti][nextj].value+1);
                        }
                    }
                }
                if(ch)  ans1++;
            }
        }
    }
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}
/*
5 8
4 5
2 8
0 0 1 1 0 0 0 0
1 0 1 1 0 1 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1

6 8
1 4
2 7
0 0 1 1 0 0 0 0
1 0 1 1 0 0 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 0 1 1 0 1 1 1
0 1 0 1 1 1 1 1

5 8
1 4
2 1
0 0 1 1 0 0 0 0
1 0 1 1 0 0 1 1
1 0 1 1 1 0 0 1
1 1 0 0 1 0 0 1
0 1 1 1 0 1 1 1
*/
