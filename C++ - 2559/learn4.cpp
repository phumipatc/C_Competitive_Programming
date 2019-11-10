#include<iostream>
#include<stdio.h>
using namespace std;
struct person{
    long long id;
    int m;
    char road[20];
}p[5];
main(){
    int i;
    char a[1000];
    for(i=0;i<3;i++){
    cout<<"ID :";
    cin>>p[i].id;
    cout<<"Moo :";
    cin>>p[i].m;
    cout<<"Road :";
    cin>>p[i].road;
    }
    FILE *fpt1;
    fpt1=fopen("test.txt","w+");
    for(i=0;i<3;i++){
        fprintf(fpt1,"%lld %d %s\n",p[i].id,p[i].m,p[i].road);
    }
    fclose(fpt1);
    fpt1=fopen("test.txt","r+");
    for(i=0;i<3;i++){
        while(fgets(a,1000,fpt1)!=NULL){
            printf("%s",a);
        }
    }
    fclose(fpt1);
return 0;
}
