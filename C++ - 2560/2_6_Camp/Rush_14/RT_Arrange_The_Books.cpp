/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[25];
set< string> sett;
set< string> ::iterator it,it2;
string ans;
int main(){
    int n,ch;
    scanf("%d",&n);
    while(n--){
        ch = 0;
        scanf(" %s",str);
        sett.insert(str);
        it = it2 = sett.lower_bound(str);
        if(it == sett.begin())  printf("N/A ");
        else{
            it--;
            ans=*it;
            printf("%s ",ans.c_str());
        }
        it2++;
        if(it2 == sett.end())   printf("N/A\n");
        else{
            ans = *it2;
            printf("%s\n",ans.c_str());
        }
    }
    return 0;
}
