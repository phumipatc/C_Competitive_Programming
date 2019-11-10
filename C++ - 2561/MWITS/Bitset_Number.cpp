/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main(){
	int lena,lenb,countt = 0;
	scanf(" %s %s",a+1,b+1);
	lena = strlen(a+1);
	lenb = strlen(b+1);
	for(int i=1;i<=lena;i++)	countt+=a[i]-'0';
	countt+=(countt%2);
	for(int i=1;i<=lenb;i++)	countt-=b[i]-'0';
	if(countt>=0)	printf("YES\n");
	else			printf("NO\n");
	return 0;
}
