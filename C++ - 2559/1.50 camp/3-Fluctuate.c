/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int main(){
    int n,min,num,i,ans=0;
    scanf("%d %d",&n,&min);
    for(i=1;i<n;i++){
        scanf("%d",&num);
        if(num-min>ans)
            ans=num-min;
        if(num<min)
            min=num;
    }
    printf("%d\n",ans);
return 0;
}
