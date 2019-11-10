/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,num,now=1;
    char r,s;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %c %c %d",&r,&s,&num);
        if(r=='M'){
            if(s=='A'){
                now=(now+num)%n;
            }else if(s=='B'){
                if(now-(num%n)<1){
                    now=now+n-(num%n);
                }else{
                    now=now-(num%n);
                }
            }
        }else if(r=='Q'){
            if(s=='A'){
                if((now+num)%n==0){
                    printf("%d\n",n);
                }else{
                    printf("%d\n",(now+num)%n);
                }
            }else if(s=='B'){
                if(now-(num%n)<1){
                    if(now+n-(num%n)==0)
                        printf("%d\n",n);
                    else
                        printf("%d\n",now+n-(num%n));
                }else{
                    if(now-(num%n)==0)
                        printf("%d\n",n);
                    else
                        printf("%d\n",now-(num%n));
                }
            }
        }
    }
	return 0;
}
