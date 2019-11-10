#include<cstdio>
#include<cstring>
using namespace std;
char a[1000],b[1000];
int main(){
    int len,i,j,sti,ch=1;
    scanf(" %s",a);
    sti=-1;
    for(i=0;i<len;i++){
        if(a[i]=='A' || a[i]=='B' || i==len-1){
            if(ch){
                for(j=i-1;j>sti;j--){
                    printf("%c",a[j]);
                }
                sti=i;
                ch=0;
            }else{
                for(j=sti+1;j<i;j++){
                    printf("%c",a[j]);
                }
                ch=1;
            }
            break;
        }
    }
    return 0;
}
