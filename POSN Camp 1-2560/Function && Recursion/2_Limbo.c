/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
char a[1200][100];
int sum=0,h,w;
void play(int i,int j)
{
    if(i-1>=0 && a[i-1][j]=='*'){
        a[i-1][j]='.';  sum++;
        play(i-1,j);
    }
    if(j-1>=0 && a[i][j-1]=='*'){
        a[i][j-1]='.'; sum++;
        play(i,j-1);
    }
    if(i+1<h && a[i+1][j]=='*'){
        a[i+1][j]='.';  sum++;
        play(i+1,j);
    }
    if(j+1<w && a[i][j+1]=='*'){
        a[i][j+1]='.';  sum++;
        play(i,j+1);
    }
}
int main()
{
    int i,j,max=-1;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            if(a[i][j]=='*'){
                sum=1;
                a[i][j]='.';
                play(i,j);
                if(sum>max)
                    max=sum;
            }
        }
    }
    printf("%d\n",max);
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
