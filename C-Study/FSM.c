#include<stdio.h>
#include<string.h>
char a[120];
int main(){
    int len,i;
    scanf(" %s",a);
    len=strlen(a);
    printf("%d ",len);
    for(i=1;i<len;i++){
        if(a[i]==a[i-1]){
            printf("Reject\n");
            return 0;
        }
    }
    printf("Accept\n");
    return 0;
}
