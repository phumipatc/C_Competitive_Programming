/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[1100];
int main()
{
    int z,i,x,ya,yb,yc,yd,ye,yf,yg,yh,yi,yj,yk,yl,ym,yn,yo,yp,yq,yr,ys,yt,yu,yv;
    int len,j,k,yw,yx,yy,yz;
    scanf("%d",&x);
    for(z=0;z<x;z++){
    ya=0,yb=0,yc=0,yd=0,ye=0,yf=0,yg=0,yh=0,yi=0,yj=0,yk=0,yl=0,ym=0,yn=0,yo=0,yp=0,yq=0,yr=0,ys=0,yt=0,yu=0,yv=0;
    yw=0,yx=0,yy=0,yz=0;
    for(i=0;i<1;i++){
        scanf(" %s",a);
        len=strlen(a);
            for(j=0;j<len;j++){
                if(a[j]==65){
                    ya++;
                }else if(a[j]==66){
                    yb++;
                }else if(a[j]==67){
                    yc++;
                }else if(a[j]==68){
                    yd++;
                }else if(a[j]==69){
                    ye++;
                }else if(a[j]==70){
                    yf++;
                }else if(a[j]==71){
                    yg++;
                }else if(a[j]==72){
                    yh++;
                }else if(a[j]==73){
                    yi++;
                }else if(a[j]==74){
                    yj++;
                }else if(a[j]==75){
                    yk++;
                }else if(a[j]==76){
                    yl++;
                }else if(a[j]==77){
                    ym++;
                }else if(a[j]==78){
                    yn++;
                }else if(a[j]==79){
                    yo++;
                }else if(a[j]==80){
                    yp++;
                }else if(a[j]==81){
                    yq++;
                }else if(a[j]==82){
                    yr++;
                }else if(a[j]==83){
                    ys++;
                }else if(a[j]==84){
                    yt++;
                }else if(a[j]==85){
                    yu++;
                }else if(a[j]==86){
                    yv++;
                }else if(a[j]==87){
                    yw++;
                }else if(a[j]==88){
                    yx++;
                }else if(a[j]==89){
                    yy++;
                }else if(a[j]==90){
                    yz++;
                }

            }
        }
        if(ya>0){
            printf("%dA",ya);
        }
        if(yb>0){
            printf("%dB",yb);
        }
        if(yc>0){
            printf("%dC",yc);
        }
        if(yd>0){
            printf("%dD",yd);
        }
        if(ye>0){
            printf("%dE",ye);
        }
        if(yf>0){
            printf("%dF",yf);
        }
        if(yg>0){
            printf("%dG",yg);
        }
        if(yh>0){
            printf("%dH",yh);
        }
        if(yi>0){
            printf("%dI",yi);
        }
        if(yj>0){
            printf("%dJ",yj);
        }
        if(yk>0){
            printf("%dK",yk);
        }
        if(yl>0){
            printf("%dL",yl);
        }
        if(ym>0){
            printf("%dM",ym);
        }
        if(yn>0){
            printf("%dN",yn);
        }
        if(yo>0){
            printf("%dO",yo);
        }
        if(yp>0){
            printf("%dP",yp);
        }
        if(yq>0){
            printf("%dQ",yq);
        }
        if(yr>0){
            printf("%dR",yr);
        }
        if(ys>0){
            printf("%dS",ys);
        }
        if(yt>0){
            printf("%dT",yt);
        }
        if(yu>0){
            printf("%dU",yu);
        }
        if(yv>0){
            printf("%dV",yv);
        }
        if(yw>0){
            printf("%dW",yw);
        }
        if(yx>0){
            printf("%dX",yx);
        }
        if(yy>0){
            printf("%dY",yy);
        }
        if(yz>0){
            printf("%dZ",yz);
        }
}return 0;
}
