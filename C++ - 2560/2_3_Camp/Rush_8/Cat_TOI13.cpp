/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2000100],b[2000100],c[2000100];
int main(){
    int n,cat;
    scanf("%d",&n);
    cat=n/2;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        b[i]=b[i*2];
    b[0]=0;
    int l=0,r=n/2;
    while(l<r){
        int mid=(l+r)/2,idx=0,ch=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b[mid]){
                idx++;
                c[idx]=a[i];
            }
        }
        for(int i=1;i<idx;i++){
            if(c[i]==c[i+1])    i++;
            else if(c[i]!=c[i+1]){
                ch=1;
                break;
            }
        }
        if(ch)  l=mid+1;
        else    r=mid;
    }
    printf("%d\n",b[l]);
    return 0;
}
