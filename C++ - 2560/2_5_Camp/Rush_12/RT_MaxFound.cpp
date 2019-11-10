/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int> mapp,idx;
char str[300005],ans[15];
int main(){
    int q,len,k,maxx,now,a,b;
    char temp;
    scanf("%d",&q);
    while(q--){
        maxx = -1;
        scanf("%d %s",&k,str+1);
        len =strlen(str+1);
        for(int i=1;i<=len-k+1;i++){
            temp = str[i+k];
            str[i+k] = NULL;
            mapp[str+i]++;
            if(!idx[str+i])  idx[str+i] = i;
            a = mapp[str+i];
            b = idx[str+i];
            if(maxx == a){
                if(now>b){
                    now = b;
                    strcpy(ans+1,str+i);
                }
            }
            if(maxx<a){
                maxx = a;
                now = b;
                strcpy(ans+1,str+i);
            }
            str[i+k] = temp;
        }
        printf("%s\n",ans+1);
        mapp.clear();
        idx.clear();
    }
    return 0;
}
