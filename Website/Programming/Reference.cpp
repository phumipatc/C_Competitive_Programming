/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int > mapp[5];
char str[55],str2[55],ans[55];
int main(){
    int len,idx,len2 = 0,countt = 0,ch = 1;
    for(int i=1;i<=4;i++){
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int k=1;k<=len;k++) str[k] = tolower(str[k]);
        for(int k=1;k<=len;k++){
            idx = 0;
            for(int l=0;l<=50;l++)  str2[l] = NULL;
            str2[idx++] = str[k];
            mapp[i][str2] = 1;
            countt = 0;
            for(int j=1;j<=i;j++)
                if(mapp[j][str2])
                    countt++;
//            printf("%d %d %d\n",countt,idx,len2);
            if(countt>=3 && idx>=len2){
                if((strcmp(ans,str2)>0 && idx == len2) || ch || idx>len2){
                    strcpy(ans,str2);
                    len2 = idx;
                    ch = 0;
//                    printf("ans : %s\n",ans);
                }
            }
//            printf("%s %d\n",str2,mapp[i][str2]);
            for(int l=k+1;l<=len;l++){
                str2[idx++] = str[l];
                mapp[i][str2] = 1;
                countt = 0;
                for(int j=1;j<=i;j++)
                    if(mapp[j][str2])
                        countt++;
//                printf("%d %d %d\n",countt,idx,len2);
                if(countt>=3){
                    if((strcmp(ans,str2)>0 && idx == len2) || ch || idx>len2){
                        strcpy(ans,str2);
                        len2 = idx;
                        ch = 0;
//                        printf("ans : %s\n",ans);
                    }
                }
//                printf("%s %d\n",str2,mapp[i][str2]);
            }
        }
    }
    printf("%s\n",ans);
    return 0;
}
