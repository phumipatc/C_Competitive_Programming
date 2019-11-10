/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char a[20000]={0},b[20000]={0};
int i,n,j,k,l,top=-1,ch;
long long num,stack[20000];
int main()
{
    scanf("%d\n",&n);
    top=-1,k=0,ch=1;
    for(i=0;i<n;i++){
        gets(a);
        l=strlen(a);
        if(l>1 && a[0]=='-' && isdigit(a[1])!=0){
            num=atol(a);
            top++;
            stack[top]=num;
        }else if(isdigit(a[0])!=0){
            num=atol(a);
            top++;
            stack[top]=num;
        }else{
            if(top<1){
                ch=0;
                break;
            }
            switch(a[j]){
                case '+' :num=stack[top-1]+stack[top]; stack[top-1]=num; top--; continue;
                case '-' :num=stack[top-1]-stack[top]; stack[top-1]=num; top--; continue;
                case '*' :num=stack[top-1]*stack[top]; stack[top-1]=num; top--; continue;
            }
        }
        if(i==n-1 && top==0){
            ch=1;
        }
    }
    if(ch==0 || top!=0)
        printf("No Solution\n");
    else
        printf("%lld\n",stack[top]);
return 0;
}
