#include<bits/stdc++.h>
using namespace std;
char str[1005];
int main(){
    int q = 10,i;
    srand(time(0));
    freopen("1.in","w",stdout);
    printf("%d\n",q);
    while(q--){
        int probability = rand()%10;
        memset(str,0,sizeof(str));
        if(probability<6){
            int len = (rand()%10)+1;
            for(i=0;i<len;i++)
                str[i] = rand()%26+'a';
            if(probability<3)
                for(i=0;i<len;i++)
                    str[2*len-1-i] = str[i];
            else
                for(i=0;i<len-1;i++)
                    str[2*len-2-i] = str[i];
        }else{
            int len = (rand()%1000)+1;
            for(i=0;i<len;i++)
                str[i] = rand()%26+'a';
        }
        printf("%s\n",str);
    }
    return 0;
}
