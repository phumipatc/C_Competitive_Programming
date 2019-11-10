/*
    Task :
    Author : Boss
    School : RYW
    Language : C++
*/
#include<bits/stdc++.h>
int main()
{
    int i,n,a,b,c;
    scanf("%d %d %d %d",&n,&a,&b,&c);
    for(i=0;i<n;i++){
        if(i%3==0){
            if(a<b && a<c){
                if(b-a>c-a){
                    a=c+abs(a-c);
                }else{
                    a=b+abs(a-b);
                }
            }else if(a<b){
                a=b+abs(a-b);
            }else{
                a=c+abs(a-c);
            }
        }else if(i%3==1){
            if(b<a && b<c){
                if(a-b>c-b){
                    b=c+abs(b-c);
                }else{
                    b=a+abs(a-b);
                }
            }else if(b<a){
                b=a+abs(b-a);
            }else{
                b=c+abs(b-c);
            }
        }else if(i%3==2){
            if(c<a && c<b){
                if(a-c>b-c){
                    c=b+abs(c-b);
                }else{
                    c=a+abs(c-a);
                }
            }else if(c<a){
                c=a+abs(c-a);
            }else{
                c=b+abs(b-c);
            }
        }
    }
    printf("%d\n%d\n%d\n",a,b,c);
    return 0;
}
