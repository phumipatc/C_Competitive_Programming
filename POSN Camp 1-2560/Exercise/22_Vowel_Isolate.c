#include<bits/stdc++.h>
using namespace std;
struct WORD{
    int vowel;
    char a[110];
    bool operator<(const WORD& o)const{
        if(vowel>o.vowel) return true;
        else if(vowel<o.vowel) return false;
        else if(strcmp(a,o.a)<0) return true;
        else                         return false;
    }
};
WORD sor[110000];
int main(){
    int q,n,i,j,len,voln=0;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf(" %s",sor[i].a);
            len = strlen(sor[i].a);
            for(j=0;j<len;j++){
                if(j != len-1 && (sor[i].a[j]=='a' || sor[i].a[j]=='e' || sor[i].a[j]=='i' || sor[i].a[j]=='o' || sor[i].a[j]=='u') && (sor[i].a[j+1]!='a' && sor[i].a[j+1]!='e' && sor[i].a[j+1]!='i' && sor[i].a[j+1]!='o' && sor[i].a[j+1]!='u')){
                    voln++;
                }
                if(j==len-1 && (sor[i].a[j]=='a' || sor[i].a[j]=='e' || sor[i].a[j]=='i' || sor[i].a[j]=='o' || sor[i].a[j]=='u')){
                    voln++;
                }
            }
            sor[i].vowel = voln;
            voln=0;
        }
        sort(sor,sor+n);
        for(i=0;i<n;i++){
            printf("%s ",sor[i].a);
        }
    }
}
