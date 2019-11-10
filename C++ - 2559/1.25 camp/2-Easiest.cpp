/*
    TASK: E
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C++
            */
#include<stdio.h>
#include<string.h>
int tree[1600000];
int main()
{
    int i,j,q,d,count=1,min,at,temp;
    char k;
    scanf("%d",&q);
    while(q--){
        scanf(" %c",&k);
        if(k=='A'){
            scanf("%d",&d);
            tree[count]=d;
            i=count;
            while(i>=2){
                if(tree[i]<tree[i/2]){
                    temp=tree[i],tree[i]=tree[i/2];
                    tree[i/2]=temp;
                    i=i/2;
                }else
                break;
            }
            count++;
        }else{
            if(count==1){
                printf("-1\n");
                continue;
            }
            printf("%d\n",tree[1]);
            tree[1]=tree[count-1];
            count--;
            i=1;
            while(i<=count){
                min=tree[i];    at=0;
                if(2*i<count && tree[2*i]<min){
                    min=tree[2*i];
                    at=1;
                }
                if(2*i+1<count && tree[2*i+1]<min){
                    min=tree[2*i+1];
                    at=2;
                }
                if(at==0){
                    break;
                }else if(at==1){
                    temp=tree[i];
                    tree[i]=tree[2*i];
                    tree[2*i]=temp;
                    i=2*i;
                }else if(at==2){
                    temp=tree[i];
                    tree[i]=tree[2*i+1];
                    tree[2*i+1]=temp;
                    i=2*i+1;
                }
            }
        }
    }
       return 0;
}
/*

*/
