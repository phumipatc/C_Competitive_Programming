#include<stdio.h>
#include<math.h>
int main()
{
   int x1,x2,x3,y1,y2,y3,x4,y4;

    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    if(x1!=x2&&x1!=x3){
        printf("%d ",x1);
    }else if(x2!=x1&&x2!=x3){
        printf("%d ",x2);
    }else{
        printf("%d ",x3);
    }if(y1!=y2&&y1!=y3){
        printf("%d ",y1);
    }else if(y2!=y1&&y2!=y3){
        printf("%d ",y2);
    }else{
        printf("%d ",y3);
    }




return 0;
}
