/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[200];
int countvowel(int len){
    int count=0;
    while(len--){
        if(a[len]=='A' || a[len]=='E' || a[len]=='I' || a[len]=='O' || a[len]=='U' || a[len]=='a' || a[len]=='e' || a[len]=='i' || a[len]=='o' || a[len]=='u'){
            count++;
        }
    }
    return count;
}
int main()
{
    int len;
    scanf(" %s",a);
    len=strlen(a);
    printf("%d",countvowel(len));
    return 0;
}
