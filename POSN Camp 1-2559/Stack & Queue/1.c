/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[500],stack[200];
int main()
{
    int q,len,top,ch,i;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a);
        top=0;
        ch=1;
        for(i=0;i<len;i++){
        if(a[i]=='(' || a[i]=='['){
            stack[top++]=a[i];
        }else{
            if(a[i]==')' && (top==0 || stack[top-1]!='(')){
                ch=0;
                break;
            }
            if(a[i]==']' && (top==0 || stack[top-1]!='[')){
                ch=0;
                break;
            }
            top--;
           }
        }
        if(ch==1 && top==0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
return 0;
}
