/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int k;
char a[3000100];
void play(int state,int win,int lose)
{
    int i;
    if(win==k||lose==k)
    {
        for(i=0; i<state; i++)
        {
            printf("%c ",a[i]);
        }
        printf("\n");
        return ;
    }
    a[state]='W';
    play(state+1,win+1,lose);
    a[state]='L';
    play(state+1,win,lose+1);

}

int main()
{
    int w,l;
    scanf("%d %d %d",&k,&w,&l);
    play(0,w,l);


    return 0;
}
