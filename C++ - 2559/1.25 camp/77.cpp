/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
int a[10][10],b[1000000],ch=0;
void raft(int i,int j,int state,int sum){
    if(state==5){
        if(b[sum]!=1)   b[sum]=1,ch++;
        return ;
    }
    if(i-1>=0)
        raft(i-1,j,state+1,sum*10+a[i-1][j]);
    if(j-1>=0)
        raft(i,j-1,state+1,sum*10+a[i][j-1]);
    if(i+1<5)
        raft(i+1,j,state+1,sum*10+a[i+1][j]);
    if(j+1<5)
        raft(i,j+1,state+1,sum*10+a[i][j+1]);
}
int main()
{
    int i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            raft(i,j,0,a[i][j]);
    printf("%d\n",ch);
return 0;
}
/*
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 1 1 1
*/
