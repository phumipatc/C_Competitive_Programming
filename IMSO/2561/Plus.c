/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
char a[5010],b[5010],c[5010];
int main(){
    scanf(" %s %s",a,b);
    int lena = strlen(a);
    int lenb = strlen(b);
    int i = lena,j = lenb,idx = 5002,tod = 0;
    if(a[0]!='-' && b[0]!='-'){
        while(i>=0 && j>=0){
            c[idx] = (((a[i]-'0')+(b[j]-'0')+tod)%10)+'0';
            if((a[i]-'0')+(b[j]-'0')+tod>=10)   tod = 1;
            else                                tod = 0;
            idx--,i--,j--;
        }
        while(i>=0){
            c[idx] = ((a[i]-'0')+tod)%10;
            if((a[i]-'0')+tod>=10)  tod = 1;
            else                    tod = 0;
            idx--,i--;
        }
        while(j>=0){
            c[idx] = ((a[j]-'0')+tod)%10;
            if((a[j]-'0')+tod>=10)  tod = 1;
            else                    tod = 0;
            idx--,j--;
        }
        for(i=idx+1;i<5002;i++){
            printf("%c",c[i]);
        }
    }else if(a[0] == '-' && b[0] == '-'){
        while(i>=1 && j>=1){
            c[idx] = (((a[i]-'0')+(b[j]-'0')+tod)%10)+'0';
            if((a[i]-'0')+(b[j]-'0')+tod>=10)   tod = 1;
            else                                tod = 0;
            idx--,i--,j--;
        }
        while(i>=1){
            c[idx] = ((a[i]-'0')+tod)%10;
            if((a[i]-'0')+tod>=10)  tod = 1;
            else                    tod = 0;
            idx--,i--;
        }
        while(j>=1){
            c[idx] = ((a[j]-'0')+tod)%10;
            if((a[j]-'0')+tod>=10)  tod = 1;
            else                    tod = 0;
            idx--,j--;
        }
        printf("-");
        for(i=idx+1;i<5002;i++){
            printf("%c",c[i]);
        }
    }else if(a[0] == '-'){
        if(lena-1>lenb)       ch = 1;
        else if(lena-1<lenb)  ch = 0;
        else{
            for(i=1;i<lena;i++){
                if(b[i-1]>a[i]){
                    ch = 0;
                    break;
                }else if(b[i-1]<a[i]){
                    ch = 1;
                    break;
                }
            }
        }
        if(ch == 1){
            printf("-");
        }else{

        }
    }else if(b[0] == '-'){
        if(lena>lenb-1)       ch = 0;
        else if(lena<lenb-1)  ch = 1;
        else{
            for(int i=1;i<lenb;i++){
                if(b[i]>a[i-1]){
                    ch = 1;
                    break;
                }else if(b[i]<a[i-1]){
                    ch = 0;
                    break;
                }
            }
        }
        if(ch == 1){
            printf("-");
        }else{

        }
    }
	return 0;
}
