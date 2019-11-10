/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int heap[2000000],count=1;
int main(){
    int n,i,j,temp,min;
    char a;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&a);
        if(a=='A'){
            scanf("%d",&heap[count]);
            for(j=count;j>1;j/=2){
                if(heap[j]<heap[j/2]){
                    temp=heap[j];
                    heap[j]=heap[j/2];
                    heap[j/2]=temp;
                }else
                    break;
            }
            count++;
        }else if(a=='B'){
            if(count==1){
                printf("-1\n");
            }else{
                printf("%d\n",heap[1]);
                heap[1]=heap[count-1];
                count--;
                for(j=1;j<count;){
                    temp=heap[j];
                    min=heap[j];
                    if(j*2<count && heap[j*2]<min)
                        min=heap[j*2];
                    if(j*2+1<count && heap[j*2+1]<min)
                        min=heap[j*2+1];
                    if(min==temp)
                        break;
                    if(min==heap[j*2]){
                        temp=heap[j];
                        heap[j]=heap[j*2];
                        heap[j*2]=temp;
                        j=j*2;
                    }else{
                        temp=heap[j];
                        heap[j]=heap[j*2+1];
                        heap[j*2+1]=temp;
                        j=j*2+1;
                    }
                }
            }
        }
    }
return 0;
}
