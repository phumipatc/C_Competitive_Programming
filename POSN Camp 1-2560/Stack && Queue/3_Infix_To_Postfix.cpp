/*
    TASK: Infix to Postfix
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stacks[20000]={0},a[200];
int main()
{
    int i,n,top=-1;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        gets(a);
        if(isalnum(a[0])!=0)
            printf("%s ",a);
        else if(a[0]=='('){
                    top++;
                    stacks[top]='(';
        }else if(a[0]==')'){
            while(1){
                if(stacks[top]=='(')
                    break;
                else{
                    printf("%c ",stacks[top]);
                    top--;
                }
            }
            top--;
        }else{
            if(a[0]=='^'){
                while(1){
                    if(top==-1 || stacks[top]=='+' || stacks[top]=='-' || stacks[top]=='*' || stacks[top]=='/' || stacks[top]=='('){
                        top++;
                        stacks[top]=a[0];
                        break;
                    }else{
                        printf("%c ",stacks[top]);
                        top--;
                    }
                }
            }
            if(a[0]=='*' || a[0]=='/'){
                while(1){
                    if(top==-1 || stacks[top]=='+' || stacks[top]=='-' || stacks[top]=='('){
                        top++;
                        stacks[top]=a[0];
                        break;
                    }else{
                        printf("%c ",stacks[top]);
                            top--;
                    }
                }
            }
            if(a[0]=='+' || a[0]=='-'){
                while(1){
                    if(top==-1 || stacks[top]=='('){
                        top++;
                        stacks[top]=a[0];
                        break;
                    }else{
                        printf("%c ",stacks[top]);
                        top--;
                    }
                }
            }
        }
    }
    while(top>=0){
        if(stacks[top]!='(')
            printf("%c ",stacks[top]);
        top--;
    }
    printf("\n");
return 0;
}
