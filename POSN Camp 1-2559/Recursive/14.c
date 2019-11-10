/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int A,B,C,mark[30];
char d[30][30][30];
void play(int a,int b,int c){
    if(a<0||b<0||c<0||a>A||b>B||c>C)
        return ;
    if(d[a][b][c]==1)
        return ;
    d[a][b][c]=1;
    if(a==0){
        mark[c]=1;
    }
    //A=>B
    play(0,a+b,c);
    play(a-B+b,B,c);
    //A=>C
    play(0,b,a+c);
    play(a-C+c,b,C);
    //B=>A
    play(a+b,0,c);
    play(A,b-A+a,c);
    //B=>C
    play(a,0,b+c);
    play(a,b-C+c,C);
    //C=>A
    play(a+c,b,0);
    play(A,b,c-A+a);
    //C=>B
    play(a,b+c,0);
    play(a,B,c-B+b);
}
int main()
{
    scanf("%d %d %d",&A,&B,&C);
    play(0,0,C);
    int i;
    for(i=0;i<=C;i++){
        if(mark[i]==1){
            printf("%d ",i);
        }
    }
return 0;
}
