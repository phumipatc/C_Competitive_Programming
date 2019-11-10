/*
    TASK:Plate
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include <stdio.h>
typedef struct{
    int id,cl;
}S;
S s[1010],q[100000];
int main()
{
    int nc,ns,id,room,front=0,rear=0,at,i;
    char a;
    scanf("%d %d",&nc,&ns);
    for(i=0;i<ns;i++)
        scanf("%d %d",&s[i].cl,&s[i].id);
    while(1){
        scanf(" %c",&a);
        if(a=='X')  break;
        if(a=='E'){
            scanf("%d",&id);
            for(i=0;i<ns;i++){
                if(s[i].id == id){
                    room=s[i].cl;   break;
                }
            }
            at=rear;
            for(i=rear-1;i>=front;i--){
                if(q[i].cl == room){
                    at=i+1;   break;
                }
            }
            for(i=rear-1;i>=at;i--)
                q[i+1]=q[i];
            q[at].id=id,q[at].cl=room;
            rear++;
        }
        if(a=='D'){
            if(front==rear){
                printf("empty\n");
            }else{
                printf("%d\n",q[front].id);
                front++;
            }
        }
    }
    printf("0\n");
return 0;
}
