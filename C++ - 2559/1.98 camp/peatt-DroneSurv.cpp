/*
TASK: Drone Survey
LANG: C
AUTHOR: PeaTT~
*/
#include<stdio.h>
int main(){
    int n,m,i,ship,move,ans;
    char t1,t2;
    scanf("%d%d",&n,&m);
    ship=1;
    for(i=0; i<m; i++){
        scanf(" %c %c",&t1,&t2);
        scanf("%d",&move);
        if(t1=='M'){
            if(t2=='A'){
                ship+=move%n;
                if(ship>n)
                    ship-=n;
            }
            if(t2=='B'){
                ship-=move%n;
                if(ship<=0)
                    ship+=n;
            }
        }
        else{
            if(t2=='A'){
                if(ship+(move%n)>n)
                    ans=ship+(move%n)-n;
                else
					ans=ship+(move%n);
            }
            if(t2=='B'){
                if(move%n==0)
                    ans=ship;
				else{
                    if(ship-(move%n)<=0)
						ans=ship-(move%n)+n;
                    else
                        ans=ship-(move%n);
                }
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}
