/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
char a[1200][100];
int h,w;
void play(int i,int j)
{
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

    if(i-1<0 && a[h-1][j]=='*'){
        a[h-1][j]='.';
        play(h-1,j);
    }
    if(j-1<0 && a[i][w-1]=='*'){
        a[i][w-1]='.';
        play(i,w-1);
    }
    if(i+1>=h && a[0][j]=='*'){
        a[0][j]='.';
        play(0,j);
    }
    if(j+1>=w && a[i][0]=='*'){
        a[i][0]='.';
        play(i,0);
    }
}
int main()
{
    int i,j,max=-1,count=0;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]=='*'){
                a[i][j]='.';
                play(i,j);
                count++;
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
