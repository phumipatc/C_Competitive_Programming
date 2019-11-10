/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, pair<int,int > > mapp;
char a[60],b[12];
int main()
{
    int q,i,n;
    char temp;
    scanf("%d",&q);
    while(q--){
        mapp.clear();
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%s",a);
            int len=strlen(a);
            if(len==44){
                for(int j=0;j<=34;j++){
                    temp=a[j+10];
                    a[j+10]='\0';
                    if(mapp[a+j].second!=i)
                        mapp[a+j].first++,mapp[a+j].second=i;
                    a[j+10]=temp;
                }
            }
            else if(len==10){
                if(mapp[a].first==0)
                    printf("not exist\n");
                else if(mapp[a].first==1)
                    printf("unique\n");
                else if(mapp[a].first>=2)
                    printf("duplicate\n");
            }
        }
    }
    return 0;
}
/*
2
5
pinkhareharehareharepinkhareharehareharepink
hareharehareharehareharehareharehareharehare
repinkhare
areharehar
pinkpinkha
3
harenarakh
harenarakharenarakharenarakharenarakharenara
harenarakh
*/

