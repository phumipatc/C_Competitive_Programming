#include<stdio.h>
int main()
{   int i,n,k,m,a,b,c,d,e,f,count=0,num=0,a1=0,b1=0,c1=0,d1=0,e1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        a1+=a; b1+=b; c1+=c; d1+=d; e1+=e;

    }
    while(a1!=0 || b1!=0 || c1!=0 || d1!=0 || e1!=0){
        if(b1!=0 && d1!=0 && c1==0){
            count++;
            b1--; d1--;
        }else if(b1==0 && c1!=0 && d1!=0){
            count++;
            c1--; d1--;
        }else if(b1!=0 && c1!=0 && d1==0){
            count++;
            b1--;
        }else if(a1!=0){
            count++; a1--;
        }else{
            f=8*a1+6*b1+4*c1+2*d1+e1;
            if(f%8!=0){
                count+=f/8+1;
            }else{
                count+=f/8;
            }
            break;
        }
    }
    printf("%d",count);

    return 0;
}
/*
3
1 0 1 0 1
0 1 0 1 0
0 1 0 0 0
*/
