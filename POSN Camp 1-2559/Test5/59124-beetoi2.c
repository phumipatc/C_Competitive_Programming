#include<stdio.h>
int a(int x){
    if(x==1)
        return 2;
    else if(x==2)
        return 4;
    else
        return a(x-1)+1+a(x-2);
}
int b(int x){
    if(x==1)
        return 4;
    else if(x==2)
        return 7;
    else
        return a(x+1);
}
int main()
{   int i,n,x,y;
    for(i=0;i<24;i++){
    scanf("%d",&n);
    if(n==-1){
        break;
    }else{
            x = a(n);
            y = b(n);
            printf("%d %d\n",x,y);
        }
    }
    return 0;
}
