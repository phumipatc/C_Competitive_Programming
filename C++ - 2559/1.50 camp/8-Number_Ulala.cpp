/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[60000];
void play(int num){
    char b[10],c[10];
    sprintf(b,"%d",num);
    int now=a[num],next;
    c[2]=b[0];  c[0]=b[1];  c[1]=b[2];  c[3]=b[3];  c[4]=b[4];
    next = atoi(c);
    if(a[next]==-1 || (a[next]!=-1 && now+1<a[next])){
        a[next]=now+1;
        play(next);
    }
    c[2]=b[4];  c[0]=b[0];  c[1]=b[1];  c[3]=b[2];  c[4]=b[3];
    next = atoi(c);
    if(a[next]==-1 || (a[next]!=-1 && now+1<a[next])){
        a[next]=now+1;
        play(next);
    }
    c[0]=b[2];  c[1]=b[0];  c[2]=b[1];  c[3]=b[3];  c[4]=b[4];
    next = atoi(c);
    if(a[next]==-1 || (a[next]!=-1 && now+1<a[next])){
        a[next]=now+1;
        play(next);
    }
    c[2]=b[3];  c[0]=b[0];  c[1]=b[1];  c[3]=b[4];  c[4]=b[2];
    next = atoi(c);
    if(a[next]==-1 || (a[next]!=-1 && now+1<a[next])){
        a[next]=now+1;
        play(next);
    }

}
int main()
{
    int q,num;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&num);
        memset(a,-1,sizeof(a));
        a[num]=0;
        play(num);
        printf("%d\n",a[12345]);
    }

    return 0;
}
/*
5 3
3 5 2 4 1
3
5
1
2
1
*/
