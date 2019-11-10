/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
int xans[1001000],yans[1001000];
int main(){
            int q,x,y;
            int xmin,xmax,ymin,ymax;
            scanf("%d",&q);
            while(q--){
		//SET START VALUE
                        xmin =  1001000;
                        xmax = -1;
                        ymin = 1001000;
                        ymax = -1;
		for(int i = 1 ; i <=3 ; i++){
			scanf("%d %d",&x,&y);
		//CALCULATE VALUE
			if(x < xmin){
                                                xmin = x;
			}
			if(x > xmax){
				xmax = x;
			}
			//
			if(y<ymin){
                                                ymin = y;
			}
			if(y > ymax){
				ymax = y;
			}
		}
                        //GOT VALUE
                        xans[xmin+1]++;
                        xans[xmax]--;
                        yans[ymin+1]++;
                        yans[ymax]--;
            }
            for(int i = 0 ; i < 1000100 ; i++){
		xans[i]+=xans[i-1];
		yans[i]+=yans[i-1];
            }
	int ask,line;
	char opr;
	scanf("%d",&ask);
	while(ask--){
		scanf(" %c = %d",&opr,&line);
                        if(opr == 'x'){
			printf("%d\n",xans[line]);
                        }else if(opr == 'y'){
			printf("%d\n",yans[line]);
                        }
	}
}
