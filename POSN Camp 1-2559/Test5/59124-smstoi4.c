/*
    TASK:
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
*/
#include<stdio.h>
#include<string.h>
char a[100],b[100];
main()
{
    int n,s,m,i,x,y,h,v;
    scanf("%d %d %d",&n,&s,&m);
    if(s==1){
        x=0,y=0;
    }else if(s==2){
        m%=3;
        x=1,y=0;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"C"); break;
            case 1:strcat(a,"A"); break;
            case 2:strcat(a,"B"); break;
        }
    }else if(s==3){
        x=2,y=0;
        m%=3;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"F"); break;
            case 1:strcat(a,"D"); break;
            case 2:strcat(a,"E"); break;
        }
    }else if(s==4){
        x=0,y=1;
        m%=3;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"I"); break;
            case 1:strcat(a,"G"); break;
            case 2:strcat(a,"H"); break;
        }
    }else if(s==5){
        m%=3;
        x=1,y=1;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"L"); break;
            case 1:strcat(a,"J"); break;
            case 2:strcat(a,"K"); break;
        }
    }else if(s==6){
        m%=3;
        x=2,y=1;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"O"); break;
            case 1:strcat(a,"M"); break;
            case 2:strcat(a,"N"); break;
        }
    }else if(s==7){
        m%=4;
        x=0,y=2;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"S"); break;
            case 1:strcat(a,"P"); break;
            case 2:strcat(a,"Q"); break;
            case 3:strcat(a,"R"); break;
        }
    }else if(s==8){
        m%=3;
        x=1,y=2;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"V"); break;
            case 1:strcat(a,"T"); break;
            case 2:strcat(a,"U"); break;
        }
    }else if(s==9){
        m%=4;
        x=2,y=2;
        strcpy(b,a);
        switch(m){
            case 0:strcat(a,"Z"); break;
            case 1:strcat(a,"W"); break;
            case 2:strcat(a,"X"); break;
            case 3:strcat(a,"Y"); break;
        }
    }
    for(i=0;i<n-1;i++){
        scanf("%d %d %d",&h,&v,&m);
        if(h==-2)
            x=x-2;
        else if(h==-1)
            x=x-1;
        else if(h==1)
            x=x+1;
        else if(h==2)
            x=x+2;
        if(v==-2)
            y=y-2;
        else if(v==-1)
            y=y-1;
        else if(v==1)
            y=y+1;
        else if(v==2)
            y=y+2;
        if(x==1 && y==0){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"C"); break;
                case 1:strcat(a,"A"); break;
                case 2:strcat(a,"B"); break;
        }
        }if(x==2 && y==0){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"F"); break;
                case 1:strcat(a,"D"); break;
                case 2:strcat(a,"E"); break;
        }
        }if(x==0 && y==1){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"I"); break;
                case 1:strcat(a,"G"); break;
                case 2:strcat(a,"H"); break;
        }
        }if(x==1 && y==1){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"L"); break;
                case 1:strcat(a,"J"); break;
                case 2:strcat(a,"K"); break;
        }
        }if(x==2 && y==1){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"O"); break;
                case 1:strcat(a,"M"); break;
                case 2:strcat(a,"N"); break;
        }
        }if(x==0 && y==2){
            m%=4;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"S"); break;
                case 1:strcat(a,"P"); break;
                case 2:strcat(a,"Q"); break;
                case 3:strcat(a,"R"); break;
        }
        }if(x==1 && y==2){
            m%=3;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"V"); break;
                case 1:strcat(a,"T"); break;
                case 2:strcat(a,"U"); break;
        }
        }if(x==2 && y==2){
            m%=4;
            strcpy(b,a);
            switch(m){
                case 0:strcat(a,"Z"); break;
                case 1:strcat(a,"W"); break;
                case 2:strcat(a,"X"); break;
                case 3:strcat(a,"Y"); break;
        }
        }
        if(x==0 && y==0){
            strcpy(a,b);
        }
    }
    int len=strlen(a);
    if(len==0){
        printf("null");
        return 0;
    }
    printf("%s",a);
    return 0;
}
