/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[12],b[12];
vector<char > aa,bb;
int main(){
    int lena,lenb,ia = 1,ib = 2;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1);
    lenb = strlen(b+1);
    while(lena>0 && lenb>0){
        if(a[lena]-'0'>b[lenb]-'0'){
            aa.push_back(a[lena]);
        }else if(a[lena]-'0'<b[lenb]-'0'){
            bb.push_back(b[lenb]);
        }else{
            aa.push_back(a[lena]);
            bb.push_back(b[lenb]);
        }
        lena--,lenb--;
    }
    while(lena>0){
        aa.push_back(a[lena]);
        lena--;
    }
    while(lenb>0){
        bb.push_back(b[lenb]);
        lenb--;
    }
    int ans = 0;
    for(int i=aa.size()-1;i>=0;i--){
        ans*=10;
        ans+=aa[i]-'0';
    }
    if(aa.size() == 0)  printf("Ern\n");
    else                printf("%d\n",ans);
    ans = 0;
    for(int i=bb.size()-1;i>=0;i--){
        ans*=10;
        ans+=bb[i]-'0';
    }
    if(bb.size() == 0)  printf("Ern\n");
    else                printf("%d\n",ans);
	return 0;
}
