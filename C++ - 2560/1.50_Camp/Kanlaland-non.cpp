#include<bits/stdc++.h>
int p[20000],power[20000];
int fin(int i){
	if(i==p[i]) return i;
	return p[i]=fin(p[i]);
}
int main(){
	int mafiaN,FightDay,personaln,personalpow,A,B,roota,rootb,ind=1;
	scanf("%d %d",&mafiaN,&FightDay);
            for(int i=1;i<=mafiaN;i++){
                        p[i]=i;
            }
            for(int i=1;i<=mafiaN;i++){
                        scanf("%d %d",&personalpow,&personaln);
                        power[i]=personaln*personalpow;
            }
            //
            for(int i=0;i<FightDay;i++){
		scanf("%d %d",&A,&B);
		roota = fin(A);
		rootb = fin(B);
		printf("Day: %d\n",ind);
		ind++;
		if(power[roota]>power[rootb]){
                                    power[roota]+=power[rootb];
			p[rootb]=p[roota];
			printf("Winner Family %d\n",roota);
		}else if(power[roota]<power[rootb]){
			power[rootb]+=power[roota];
			p[roota]=p[rootb];
			printf("Winner Family %d\n",rootb);
		}else if(roota==rootb){
			printf("Family don't need to make war\n");
		}else{
			printf("Draw\n");
		}
            }
}
