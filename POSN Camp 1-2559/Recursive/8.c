/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int m,n,len,c[100][100],d[1000][2],ch;
char a[1000][1000];
char b[1000];
void play(int i,int j,int state){
    int k,l;
    d[state][0]=i+1,d[state][1]=j+1;
    if(state==len-1){
        ch=0;
        for(k=0;k<len;k++)
            printf("%d %d\n",d[k][0],d[k][1]);
        return ;
    }
    if(i-1>=0 && a[i-1][j]==b[state+1] && c[i-1][j]!=1){
        c[i-1][j]=1;
        play(i-1,j,state+1);
        c[i-1][j]=0;
    }
    if(j-1>=0 && a[i][j-1]==b[state+1] && c[i][j-1]!=1){
        c[i][j-1]=1;
        play(i,j-1,state+1);
        c[i][j-1]=0;
    }
    if(i+1<m && a[i+1][j]==b[state+1] && c[i+1][j]!=1){
        c[i+1][j]=1;
        play(i+1,j,state+1);
        c[i+1][j]=0;
    }
    if(j+1<n && a[i][j+1]==b[state+1] && c[i][j+1]!=1){
        c[i][j+1]=1;
        play(i,j+1,state+1);
        c[i][j+1]=0;
    }

}
int main()
{
    int i,j,q;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf(" %c",&a[i][j]);
            a[i][j]=tolower(a[i][j]);
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%s",b);
        len=strlen(b);
        for(i=0;i<len;i++)
            b[i]=tolower(b[i]);
            ch=1;
        for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    if(a[i][j]==b[0]){
                        c[i][j]=1;
                        play(i,j,0);
                        c[i][j]=0;
                    }
            }
    }
    if(ch)
        printf("No Matching Word\n");
    }
return 0;
}
