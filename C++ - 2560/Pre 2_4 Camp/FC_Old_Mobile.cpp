/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[105];
int pos[10];
int countt(char c){
    if(c=='a' || c=='d' || c=='g' || c=='j' || c=='m' || c=='p' || c=='t' || c=='w')
        return 1;
    else if(c=='b' || c=='e' || c=='h' || c=='k' || c=='n' || c=='q' || c=='u' || c=='x')
        return 2;
    else if(c=='c' || c=='f' || c=='i' || c=='l' || c=='o' || c=='r' || c=='v' || c=='y')
        return 3;
    else if(c=='s' || c=='z')
        return 4;
}
int position(int c){
    if(c=='a' || c=='b' || c=='c')                  return 2;
    else if(c=='d' || c=='e' || c=='f')             return 3;
    else if(c=='g' || c=='h' || c=='i')             return 4;
    else if(c=='j' || c=='k' || c=='l')             return 5;
    else if(c=='m' || c=='n' || c=='o')             return 6;
    else if(c=='p' || c=='q' || c=='r' || c=='s')   return 7;
    else if(c=='t' || c=='u' || c=='v')             return 8;
    else                                            return 9;
}
int main(){
    int num,last=0;
    for(int i=1;i<=9;i++){
        scanf("%d",&num);
        pos[num]=i;
    }
    scanf(" %s",str+1);
    int len=strlen(str+1),now;
    for(int i=1;i<=len;i++){
        now=position(str[i]);
        if(now==last)   printf("#");
        num=countt(str[i]);
        while(num--)    printf("%d",pos[now]);
        last=now;
    }
    return 0;
}
