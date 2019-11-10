/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
#include<string.h>
char str[20];
int main(){
    int q,len,i,sum;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str);
        sum = 0;
        len = strlen(str);
        for(i = 0;i<len;i++){
            if(str[i] == 'M')
                sum+=1000;
            else if(str[i] == 'C' && str[i+1] == 'M')
                sum+=900,i++;
            else if(str[i] == 'D')
                sum+=500;
            else if(str[i] == 'C' && str[i+1] == 'D')
                sum+=400,i++;
            else if(str[i] == 'C')
                sum+=100;
            else if(str[i] == 'X' && str[i+1] == 'C')
                sum+=90,i++;
            else if(str[i] == 'L')
                sum+=50;
            else if(str[i] == 'X' && str[i+1] == 'L')
                sum+=40,i++;
            else if(str[i] == 'X')
                sum+=10;
            else if(str[i] == 'I' && str[i+1] == 'X')
                sum+=9,i++;
            else if(str[i] == 'V')
                sum+=5;
            else if(str[i] == 'I' && str[i+1] == 'V')
                sum+=4;
            else if(str[i] == 'I')
                sum++;
        }
        printf("%d\n",sum);
    }
	return 0;
}
