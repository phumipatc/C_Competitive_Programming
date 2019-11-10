/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
int n,count;
char a[30],b[100000][30];
void func(int op,int cl){
    int at=op+cl;
    if(op<n || cl<n){
        if(op<n){
            a[at]='(';
            func(op+1,cl);
        }
        if(cl<n && cl<op){
            a[at]=')';
            func(op,cl+1);
        }
    }else{
        memcpy(b[count++],a,at);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    func(0,0);
    printf("%d\n",count);
    for(i=0;i<count;i++){
        printf("%s\n",b[i]);
    }
return 0;
}
