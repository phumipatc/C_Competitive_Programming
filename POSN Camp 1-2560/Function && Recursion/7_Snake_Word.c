/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[100][100],b[1000];
int r,c,ch,d[1000][2],len,dir[4]={0,0,1,-1},dic[4]={1,-1,0,0};
void play(int i,int j,int state){
    int k,newi,newj;
    d[state][0]=i+1,d[state][1]=j+1;
    if(state==len-1){
        ch=0;
        for(k=0;k<len;k++)
            printf("%d %d\n",d[k][0],d[k][1]);
        return ;
    }
    char old=a[i][j];
    a[i][j]='7';
    for(k=0;k<4;k++){
        newi=i+dir[k];
        newj=j+dic[k];
        if(newi<0 || newj<0 || newi>=r || newj>=c)
            continue;
        if(a[newi][newj]!=b[state+1] || a[newi][newj]=='7')
            continue;
        play(newi,newj,state+1);
    }
    a[i][j]=old;
}
int main()
{
    int i,j,q;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            a[i][j]=toupper(a[i][j]);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf(" %s",b);
        len=strlen(b);
        for(i=0;i<len;i++)
            b[i]=toupper(b[i]);
        ch=1;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(a[i][j]==b[0]){
                    char old=a[i][j];
                    a[i][j]='7';
                    play(i,j,0);
                    a[i][j]=old;
                }
            }
        }
        if(ch)
            printf("No Matching Word\n");
    }
    return 0;
}
/*
3 5
TAEPE
TULAR
STOPW
2
PEATT
HELLOWORLD
*/
