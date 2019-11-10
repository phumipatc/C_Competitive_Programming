/*
    TASK:Fractral
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<stdio.h>
#include<math.h>

int main()
{
   int i,n,r,x,y,j;
   scanf(" %d",&n);
   i=pow(2.00,(n-1));
   j=pow(2.00,n)-1;
   for(r=1;r<=j;r++){
       if(r%4==1){
           for(x=0;x<(r-1)/2;x++)
               printf("-");
           printf("*");
           for(x=0;x<(i-((r-1)/2-1)-2);x++)
               printf("-");
       }else if(r%4==2){
           for(x=0;x<r/2-1;x++)
               printf("-");
           printf("**");
           for(x=0;x<(i-(r/2-1)-2);x++)
               printf("-");
       }else if(r%4==3){
           for(x=0;x<(r-1)/2;x++)
               printf("-");
           printf("*");
           for(x=0;x<(i-((r-1)/2-1))-2;x++)
               printf("-");
       }else if(r%4==0 && r%8!=0){
           for(x=0;x<(r-4)/2;x++)
               printf("-");
           for(x=0;x<4;x++)
               printf("*");
           for(x=0;x<i-(r-4)/2-4;x++)
               printf("-");
       }
       if(r%8==0 && r%16!=0){
           for(x=0;x<(r-8)/2;x++)
               printf("-");
           for(x=0;x<8;x++)
               printf("*");
           for(x=0;x<i-(r-8)/2-8;x++)
               printf("-");
       }
       if(r%16==0 && r%32!=0){
           for(x=0;x<(r-16)/2;x++)
               printf("-");
           for(x=0;x<16;x++)
               printf("*");
           for(x=0;x<i-(r-16)/2-16;x++)
               printf("-");
       }
       if(r%32==0 && r%64!=0){
           for(x=0;x<(r-32)/2;x++)
               printf("-");
           for(x=0;x<32;x++)
               printf("*");
           for(x=0;x<i-(r-32)/2-32;x++)
               printf("-");
       }
       if(r%64==0 && r%128!=0){
           for(x=0;x<(r-64)/2;x++)
               printf("-");
           for(x=0;x<64;x++)
               printf("*");
           for(x=0;x<i-(r-64)/2-64;x++)
               printf("-");
       }
       if(r%128==0 && r%256!=0){
           for(x=0;x<(r-128)/2;x++)
               printf("-");
           for(x=0;x<128;x++)
               printf("*");
           for(x=0;x<i-(r-128)/2-128;x++)
               printf("-");
       }
       if(r%256==0 && r%512!=0){
           for(x=0;x<(r-256)/2;x++)
               printf("-");
           for(x=0;x<256;x++)
               printf("*");
           for(x=0;x<i-(r-256)/2-256;x++)
               printf("-");
       }
       if(r%512==0 && r%1024!=0){
           for(x=0;x<(r-512)/2;x++)
               printf("-");
           for(x=0;x<512;x++)
               printf("*");
           for(x=0;x<i-(r-512)/2-512;x++)
               printf("-");
       }
       if(r%1024==0 && r%2048!=0){
           for(x=0;x<(r-1024)/2;x++)
               printf("-");
           for(x=0;x<1024;x++)
               printf("*");
           for(x=0;x<i-(r-1024)/2-1024;x++)
               printf("-");
       }
       if(r%2048==0 && r%4096!=0){
           for(x=0;x<(r-2048)/2;x++)
               printf("-");
           for(x=0;x<2048;x++)
               printf("*");
           for(x=0;x<i-(r-2048)/2-2048;x++)
               printf("-");
       }
       printf("\n");
   }
   return 0;
}
