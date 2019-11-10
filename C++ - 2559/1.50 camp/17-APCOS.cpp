/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
typedef struct{
    int x1,y1,x2,y2,index;
}window;
window w[1200],temp;
int main(){
    int i,n,top,t,x,y,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&w[i].x1,&w[i].y1,&w[i].x2,&w[i].y2);
        w[i].index=i+1;
    }
    scanf("%d",&t);
    top=n-1;
    while(t--){
        scanf("%d %d",&x,&y);
        for(i=top;i>=0;i--){
            if(x==w[i].x1 && y==w[i].y1){
                for(j=i;j<top;j++)
                    w[j]=w[j+1];
                top--;
                break;
            }
            if(x>=w[i].x1 && x<=w[i].x2 && y>=w[i].y1 && y<=w[i].y2){
                temp=w[i];
                for(j=i;j<top;j++)
                    w[j]=w[j+1];
                w[top]=temp;
                break;
            }
        }
    }
    if(top==-1)
        printf("DESKTOP");
    else
        printf("%d",w[top].index);
return 0;
}
/*
2 0 0 60 60
50 50 120 90
5
50 51
25 25
60 60
61 30
0 0

2
21 21 40 40
10 10 20 20
4
20 20
21 20
21 21
10 10
*/
