#include<bits/stdc++.h>
using namespace std;
string a[100100];
bool cmp(string x,string y){
    if(x+y < y+x)   return true;
    else            return false;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    for(i=0;i<n;i++)
        cout<<a[i];
    return 0;
}
