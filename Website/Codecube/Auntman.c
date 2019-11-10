/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
char a[2000][2000];
int main()
{
    int n,m,i,count=0,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf(" %s",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='x'){
                a[i][j]='.';
                if(i+1<n && j+1<m && a[i+1][j+1]=='A')          a[i+1][j+1]='.';
                if(i+2<n && j+2<m && a[i+2][j+2]=='A')        a[i+2][j+2]='.';
                if(i+1<n && j-1>=0 && a[i+1][j-1]=='A')         a[i+1][j-1]='.';
                if(i+2<n && j-2>=0 && a[i+2][j-2]=='A')       a[i+2][j-2]='.';
                if(i-1>=0 && j+1<m && a[i-1][j+1]=='A')         a[i-1][j+1]='.';
                if(i-2>=0 && j+2<m && a[i-2][j+2]=='A')       a[i-2][j+2]='.';
                if(i-1>=0 && j-1>=0 && a[i-1][j-1]=='A')        a[i-1][j-1]='.';
                if(i-2>=0 && j-2>=0 && a[i-2][j-2]=='A')      a[i-2][j-2]='.';
            }else if(a[i][j]=='+'){
                a[i][j]='.';
                if(i+1<n && a[i+1][j]=='A')     a[i+1][j]='.';
                if(i-1>=0 && a[i-1][j]=='A')    a[i-1][j]='.';
                if(j+1<m && a[i][j+1]=='A')     a[i][j+1]='.';
                if(j-1>=0 && a[i][j-1]=='A')    a[i][j-1]='.';
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='A')
                count++;
        }
    }
    printf("%d\n",count);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
5 7
A..A...
.A..A..
.Ax.+..
...A...
......A
*/
