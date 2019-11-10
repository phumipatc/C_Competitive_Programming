/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int A,B,C,d[30],mark[25][25][25];
void insert(int aa,int bb,int cc){
    if(aa<0 || bb<0 || cc<0 || aa>A || bb>B || cc>C)
        return ;
    if(mark[aa][bb][cc]==1)
        return ;
    mark[aa][bb][cc]=1;
    if(aa==0)
        d[cc]=1;
    insert(0       ,aa+bb   ,cc);       insert(aa+bb-B ,B       ,cc);
    insert(0       ,bb      ,aa+cc);    insert(aa+cc-C ,bb       ,C);

    insert(aa+bb   ,0       ,cc);       insert(A       ,aa+bb-A ,cc);
    insert(aa      ,0       ,bb+cc);    insert(aa      ,bb+cc-C ,C);

    insert(aa+cc   ,bb      ,0);        insert(A       ,bb      ,aa+cc-A);
    insert(aa      ,bb+cc   ,0);        insert(aa      ,B       ,bb+cc-B);
}
int main()
{
    int i;
    scanf("%d %d %d",&A,&B,&C);
    insert(0,0,C);
    for(i=0;i<=C;i++)
        if(d[i]==1)
            printf("%d ",i);
    printf("\n");
    return 0;
}
