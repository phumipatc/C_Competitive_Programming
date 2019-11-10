/*
    TASK: Limbo
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
char a[2000][2000];
int h,w;
void play(int i,int j){
    if(i-1>=0 && a[i-1][j]=='*'){
        a[i-1][j]='.';
        play(i-1,j);
    }
    if(j-1>=0 && a[i][j-1]=='*'){
        a[i][j-1]='.';
        play(i,j-1);
    }
    if(i+1<h && a[i+1][j]=='*'){
        a[i+1][j]='.';
        play(i+1,j);
    }
    if(j+1<w && a[i][j+1]=='*'){
        a[i][j+1]='.';
        play(i,j+1);
    }
    if(j==0 && a[i][w-1]=='*'){
        a[i][w-1]='.';
        play(i,w-1);
    }
    if(j==w-1 && a[i][0]=='*'){
        a[i][0]='.';
        play(i,0);
    }
    if(i==0 && a[h-1][j]=='*'){
        a[h-1][j]='.';
        play(h-1,j);
    }
    if(i==h-1 && a[0][j]=='*'){
        a[0][j]='.';
        play(0,j);
    }
}
int main()
{
   int i,j,count=0;
   scanf("%d %d",&w,&h);
   for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]=='*'){
                count++;
                a[i][j]='.';
                play(i,j);
            }
        }
    }
   printf("%d\n",count);
   return 0;
}

/*
    TASK:Limbo
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
/*
#include<stdio.h>
char a[2000][2000];
int h,w;
void play(int i,int j){
    if(i-1>=0 && a[i-1][j]=='*'){
        a[i-1][j]='.';
        play(i-1,j);
    }
    if(j-1>=0 && a[i][j-1]=='*'){
        a[i][j-1]='.';
        play(i,j-1);
    }
    if(i+1<h && a[i+1][j]=='*'){
        a[i+1][j]='.';
        play(i+1,j);
    }
    if(j+1<w && a[i][j+1]=='*'){
        a[i][j+1]='.';
        play(i,j+1);
    }
    if(j==0 && a[i][w-1]=='*'){
        a[i][w-1]='.';
        play(i,w-1);
    }
    if(j==w-1 && a[i][0]=='*'){
        a[i][0]='.';
        play(i,0);
    }
    if(i==0 && a[h-1][j]=='*'){
        a[h-1][j]='.';
        play(h-1,j);
    }
    if(i=h-1 && a[0][j]=='*'){
        a[0][j]='.';
        play(0,j);
    }
}
int main()
{
    int i,j,count=0;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]=='*'){
                count++;
                a[i][j]='.';
                play(i,j);
            }
        }
    }
    printf("%d\n",count);
return 0;
}
/*
10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
*/
